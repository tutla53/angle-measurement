#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat image, img2;
//int points[5][2];


void CallBackFunc(int event, int x, int y, int flags, void* userdata){
    Point pt;
    if(event == EVENT_LBUTTONDOWN){
        pt.x = x; pt.y = y;
        printf("Position %d %d\n",x,y);
        circle(img2, pt, 3, Scalar(0,0,255),FILLED);
    }
}


int main(){
    bool end = 0;
    String src ="img/P070.JPG";
    char wait_char;

    image = imread(src,cv::IMREAD_COLOR);
    resize(image, img2, Size(1400,1050), INTER_LINEAR);
    if(! image.data){
            printf("Could not open file\n");
            return -1;
    }

    while(!end){
        namedWindow("Image", cv::WINDOW_AUTOSIZE);
        imshow("Image", img2);
        setMouseCallback("Image",CallBackFunc,NULL);
        wait_char = waitKey(10);
        if(wait_char == 's'){
            destroyAllWindows();
            end = 1;
            return 0;
        }
        else if(wait_char == 'a'){
            image = imread(src,cv::IMREAD_COLOR);
            resize(image, img2, Size(1400,1050), INTER_LINEAR);
        }
    }
    return 0;
}