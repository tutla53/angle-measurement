#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

#define circle_width 3
#define line_width   2
#define X_size       1400
#define Y_size       1050
#define offset       700
#define pi           3.1415926


Mat image, img2;
bool mouse_event = 0;


void CallBackFunc(int event, int x, int y, int flags, void *ptr){
    Point*p = (Point*)ptr;
    if(event == EVENT_LBUTTONDOWN){
        p->x = x; 
        p->y = y;
        circle(img2, Point(x,y), circle_width, Scalar(0,0,255),FILLED);
        mouse_event = 1;
    }
}

double gradient(Point pt1, Point pt2){
    /*Calculate the slope of two points*/
    double m;
    m = double(pt2.y - pt1.y)/double(pt2.x - pt1.x);
    return m;
}

double rad2deg(double rad){
    /*Convert radians to degrees*/
    double deg = 0;
    deg = rad * (180.0/pi);
    return deg;
}


int main(){
    bool end = 0, status;
    char wait_char;
    double m1 = 0, l_x, l_y, angR, angD;
    uint8_t i = 0;
    String source    = "img/source/",
           result    = "img/result/",
           filename  = "P070",
           filetype  = ".JPG",
           path      = source+filename+filetype;   

    Point pt, pnt[6];

    image = imread(path,IMREAD_COLOR);
    resize(image, img2, Size(X_size,Y_size), INTER_LINEAR);

    if(! image.data){
            printf("Could not open file\n");
            return -1;
    }

    while(!end){
        namedWindow("Image", cv::WINDOW_AUTOSIZE);
        imshow("Image", img2);
        setMouseCallback("Image",CallBackFunc, &pt);
        
        if(mouse_event){
            if(i<6){
                if(i == 0){
                    pnt[0].x = pt.x; pnt[0].y = pt.y;
                    pnt[1].x = pt.x; pnt[1].y = pt.y - offset;
                    line(img2, pnt[0],pnt[1], Scalar(0,0,255),line_width);
                    circle(img2, pnt[i+1], circle_width, Scalar(0,0,255),FILLED);
                    printf("Point %d: %d %d \n",0,pnt[0].x,pnt[0].y);
                    printf("Point %d: %d %d \n",1,pnt[1].x,pnt[1].y);
                    i += 2;
                }
                else if(i == 2){
                    pnt[2].x = pt.x; pnt[2].y = pt.y;
                    printf("Point %d: %d %d \n",2,pnt[2].x,pnt[2].y);
                    i++;
                }
                else if(i == 3){
                    pnt[3].x = pt.x; pnt[3].y = pt.y;
                    pnt[4].x = round((pnt[3].x + pnt[2].x)/2);
                    pnt[4].y = round((pnt[3].y + pnt[2].y)/2);

                    m1 = -1/gradient(pnt[3],pnt[2]);
                    
                    pnt[5].y = round(((pnt[0].x - pnt[4].x)*m1) + pnt[4].y);
                    pnt[5].x = pnt[0].x;

                    line(img2, pnt[2],pnt[3], Scalar(0,0,255),line_width);
                    circle(img2, pnt[4], circle_width, Scalar(0,0,255),FILLED);
                    line(img2, pnt[5],pnt[4], Scalar(0,0,255),line_width);
                    circle(img2, pnt[5], circle_width, Scalar(0,0,255),FILLED);


                    printf("Point %d: %d %d \n",3,pnt[3].x,pnt[3].y);
                    printf("Point %d: %d %d \n",4,pnt[4].x,pnt[4].y);
                    printf("Point %d: %d %d \n",5,pnt[5].x,pnt[5].y);

                    /*Calculate angle of the tip*/
                    l_x = abs(double(pnt[0].x - pnt[4].x));
                    l_y = abs(double(pnt[5].y - pnt[4].y));

                    angR = atan(l_x/l_y);
                    angD = rad2deg(angR);

                    /*Quadrant correction measured from the neutral axis of the robot*/
                    if(pnt[4].x < pnt[0].x){
                        if(m1<0) angD = 180 - angD;
                    }
                    else if (pnt[4].x > pnt[0].x){
                        if(m1>0) angD = 180 + angD;
                        else angD = 360 - angD;
                    }
                    
                    printf("Angle: %lf\n",angD);
                    angD = int(round(angD)) % 360;

                    /*Put the text to the window*/                
                    putText(img2, to_string(int(angD)), Point(pnt[4].x+75,pnt[4].y-10), FONT_HERSHEY_COMPLEX, 1.5, Scalar(0,0,0),2);                    
                    i+=3;
                }
            }                   
            mouse_event = 0;
        }

        wait_char = waitKey(10);
        if(wait_char == 's'){
            /*Save the result*/
            status = imwrite(result+filename+"_final"+filetype, img2);
            printf("Image written to file-system : %d\n",status);
        }
        else if(wait_char == 'a'){
            /*Clear the window*/
            i = 0;
            image = imread(path,cv::IMREAD_COLOR);
            resize(image, img2, Size(X_size,Y_size), INTER_LINEAR);
        }
        else if(wait_char == 'q'){
            /*Exit*/
            destroyAllWindows();
            end = 1;
        }
    }
    return 0;
}