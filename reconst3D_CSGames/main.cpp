#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/calib3d/calib3d.hpp>

#include <iostream>

using namespace cv;
using namespace std;


//! Calibration matrices
Mat KLeft;
Mat KRight;
Mat R;
Mat T;

int main( int argc, char** argv )
{
    //! [load images]
    String imLeft_file( "left_im.png" );
    String imRight_file( "right_im.png" );
    Mat imLeft; Mat imRight;

    imLeft = imread( imLeft_file , IMREAD_COLOR ); // Read the file
    imRight = imread( imRight_file , IMREAD_COLOR ); // Read the file

    Size sLeft = imLeft.size();
    int rowsLeft = sLeft.height;
    int colsLeft = sLeft.width;
    Size sRight = imRight.size();
    int rowsRight = sRight.height;
    int colsRight = sRight.width;

    if( imLeft.empty() || imRight.empty())                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << endl ;
        return -1;
    }

    //stereoRectify input
    Mat distort = (Mat_<double>(8,1) << 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);
    Size newImageSize = imLeft.size();
    //Call function
    //stereoRectify();
    //initUndistortRectifyMap();
    //initUndistortRectifyMap();
    //remap();


    //! [ Matching ]
    Mat result;
    int windwsize = 3;
    int iend = 0;
    int jend = 0;

    for (int i=0; i<iend; i++)
    {
        Mat imRightLine;
        for (int j=0; j<0; j++)
        {
            Mat templ;
            matchTemplate(imRightLine, templ, result, CV_TM_CCOEFF_NORMED);

        }
    }


    //! [ display image in window]
    namedWindow( "Display left image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display left image", imLeft );                // Show our image inside it.
    namedWindow( "Display right image", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display right image", imRight );                // Show our image inside it.

    waitKey(0); // Wait for a keystroke in the window

    return 0;
}
