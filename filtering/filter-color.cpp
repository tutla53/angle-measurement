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
int thresh = 0;
int imratio = 2;
int max_thresh = 255;
const char* source_window = "Source image";
const char* filtered_window = "Filtered Window";

bool mouse_event = 0;

void thresh_callback(int, void* ){
    assert(src.type() == CV_8UC3);

    Mat redOnly;
    inRange(src, Scalar(0, 0, 0), Scalar(0,thresh, 0), redOnly);
    namedWindow( filtered_window);
    imshow( filtered_window, redOnly);

}

int main(){
    char wait_char;
    bool status;
    String source    = "../img/source/",
           result    = "../img/result/",
           filename  = "P070_crop",
           filetype  = ".JPG",
           path      = source+filename+filetype;   

    image = imread(path,IMREAD_COLOR);

    if(!image.data){
            printf("Could not open file\n");
            return -1;
    }
    resize(image, src, Size(X_size,Y_size), INTER_LINEAR);

    namedWindow(source_window );
    createTrackbar("Color Tresh",source_window,&thresh, max_thresh, thresh_callback);
    imshow(source_window, src);
    thresh_callback(0,0);

    waitKey(0);

    return 0;
}