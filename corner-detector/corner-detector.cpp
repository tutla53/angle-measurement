#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;

#define circle_width 3
#define line_width   2
#define size_scale   0.5
#define X_size       1200 * size_scale
#define Y_size       1200 * size_scale
#define offset       700
#define pi           3.1415926

Mat image, src, src_gray;
int thresh = 75;
int imratio = 2;
int max_thresh = 255;
const char* source_window = "Source image";
const char* corners_window = "Corners detected";

bool mouse_event = 0;


void cornerHarris_demo( int, void* ){
    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;

    Mat dst = Mat::zeros( src.size(), CV_32FC1 );
    cornerHarris( src_gray, dst, blockSize, apertureSize, k );

    Mat dst_norm, dst_norm_scaled;
    normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
    convertScaleAbs( dst_norm, dst_norm_scaled );

    for( int i = 0; i < dst_norm.rows ; i++ ){
        for( int j = 0; j < dst_norm.cols; j++ ){
            if( (int) dst_norm.at<float>(i,j) > thresh ){
                circle(dst_norm_scaled, Point(j,i), 5,  Scalar(0,0,255), FILLED);
            }
        }
    }
    
    namedWindow( corners_window );
    imshow( corners_window, dst_norm_scaled );
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


int main(){
    char wait_char;
    bool status;
    String source    = "../img/result/",
           result    = "../img/result/",
           filename  = "P070_crop3_contour",
           filetype  = ".png",
           path      = source+filename+filetype;   

    image = imread(path,IMREAD_COLOR);

    if(!image.data){
            printf("Could not open file\n");
            return -1;
    }
    src = image;
    //resize(image, src, Size(X_size,Y_size), INTER_LINEAR);

    cvtColor( src, src_gray, COLOR_BGR2GRAY );

    namedWindow(source_window );
    createTrackbar("Threshold: ", source_window, &thresh, max_thresh, cornerHarris_demo );
    imshow(source_window, src );
    cornerHarris_demo( 0, 0 );
    waitKey();

    waitKey(0);
   
    return 0;
}