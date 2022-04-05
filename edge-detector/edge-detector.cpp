#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;

#define circle_width 3
#define line_width   2
#define size_scale   0.8
#define X_size       1400 * size_scale
#define Y_size       1050 * size_scale
#define offset       700
#define pi           3.1415926

Mat image, src, src_gray;
Mat dst, detected_edges;

int lowThreshold = 0;
const int max_lowThreshold = 255;
const int imratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";

bool mouse_event = 0;

static void CannyThreshold(int, void*){
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*imratio, kernel_size);
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );
}

void CallBackFunc(int event, int x, int y, int flags, void *ptr){
    Point*p = (Point*)ptr;
    if(event == EVENT_LBUTTONDOWN){
        p->x = x; 
        p->y = y;
        circle(src, Point(x,y), circle_width, Scalar(0,0,255),FILLED);
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

    String source    = "../img/source/",
           result    = "../img/result/",
           filename  = "P070",
           filetype  = ".JPG",
           path      = source+filename+filetype;   

    image = imread(path,IMREAD_COLOR);

    if(!image.data){
            printf("Could not open file\n");
            return -1;
    }
    resize(image, src, Size(X_size,Y_size), INTER_LINEAR);

    dst.create( src.size(), src.type() );
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    namedWindow( window_name, WINDOW_AUTOSIZE );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
    CannyThreshold(0, 0);

    waitKey(0);
   
    return 0;
}