#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
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
Mat dst, detected_edges, drawing;

int lowThreshold = 40;
const int max_thresh = 255;
const int imratio = 2;
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


void thresh_callback(int, void* ){
    Mat canny_output;
    Canny( src_gray, canny_output, lowThreshold, lowThreshold*imratio);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
    drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ ){
        Scalar color = Scalar( 255, 255, 255);
        drawContours( drawing, contours, (int)i, color, 1, LINE_8, hierarchy, 0 );
    }
    imshow( "Contours", drawing );
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
    char wait_char;
    bool status;
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

    cvtColor(src, src_gray, COLOR_BGR2GRAY );
    blur(src_gray,src_gray,Size(3,3));

    const char* source_window = "Source";
    namedWindow(source_window );
    imshow(source_window, src);

    createTrackbar( "Canny thresh:", source_window, &lowThreshold, max_thresh, thresh_callback);
    thresh_callback( 0, 0 );

    while(1){
    wait_char = waitKey(10);
        if(wait_char == 's'){
            /*Save the result*/
            status = imwrite(result+filename+"_contour"+filetype, drawing);
            printf("Image written to file-system : %d\n",status);
            break;
        }
    }
    return 0;
}