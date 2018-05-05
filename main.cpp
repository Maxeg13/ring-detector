#include <QApplication>
#include <iostream>

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <QDebug>

#include "detector.h"
//#include <opencv/>
using namespace std;
using namespace cv;






int ddepth;
int kernel_size;
double delta;

int thresh(int x, int y)
{
    if(x<0)
        return(0);
    if(x>(y-1))
        return(y-1);
    return(x);

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    detector det=detector();
    Mat face_src;
    face_src=imread("C://Users\\chibi\\Documents\\Lightshot\\Screenshot_3.png");

    Mat dst, src, src2;
    char* c1="first";
    char* c2="second";
    char* c3="third";
    Point anchor;
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = -1;
    int s=120;

    int i,j, ind_1, ind_2;


    float sum=0;

    //    kernel/=sum;
    //    cvtColor(kernel,kernel,CV_GRAY)
    float sc=0.3;

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    std::vector<Rect> faces;
    vector<Rect> r;
    r.resize(1);

    //    cvtColor(kernel,kernel, CV_8UC4);

    namedWindow( c1, CV_WINDOW_AUTOSIZE);
    namedWindow( c2, CV_WINDOW_AUTOSIZE);
    namedWindow( c3, CV_WINDOW_AUTOSIZE);
    imshow(c3, det.kernel[1]);
    //    imshow(c1, src);
    //    imshow(c1, kernel*sum);
    cap >> src2;
    Mat mean, out_std;
    Mat form=Mat::ones(src2.size().width, src2.size().height, CV_32F );
    for(;;)
    {
        //        resize(src2,src2,Size(30,30));
        cap >> src; // get a new frame from camera
        //        qDebug()<<src.at<uint16_t>(Point(1,1));

        //        meanStdDev(src,mean,out_std);
        //        src/=3;
        cvtColor(src, dst, CV_BGR2GRAY);
        //        dst.copyTo(form);
        //        cvtColor(dst,form,CV_GRAY)
//        matchTemplate(dst, det.core_kernel, out_std, TM_CCORR_NORMED);
        det.multiMax(dst);
        //                qDebug()<<out_std.type();


//        Mat x_mat=;
        float max1=0;
        int bar=30;
//        int ind_1, ind_2;
//        det.getMax(out_std,ind_1, ind_2, max1);

        qDebug()<<det.max;
        if(det.max>0.64)
            rectangle(src,Rect(det.ind_1+det.dst_s/4,det.ind_2+det.dst_s/4,bar+det.dst_s/2,bar+det.dst_s/2),Scalar(255,255,255),5);
        imshow(c2, src);
//        imshow(c1, det.out_std);
        src2=src;

        if(waitKey(30) >= 0) break;
    }


    return a.exec();
}
