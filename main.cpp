#include <QCoreApplication>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mat src = imread("/home/lin/workspace/医疗检查报告/6.jpg",1);
    cvtColor(src,src,CV_BGR2GRAY);
    Size size = src.size();
    Canny(src,src,100,300,3);
    vector<Vec4i> lines;
    HoughLinesP(src, lines, 80, CV_PI/2, CV_THRESH_OTSU|CV_THRESH_BINARY, 110, 10);
    Mat disp_lines(size, CV_8UC1, cv::Scalar(0, 255, 0));
    double angle = 0.,ang = 0.;
    unsigned nb_lines = lines.size();
    for (unsigned i = 0; i < nb_lines; ++i)
    {
        angle = atan2((double)lines[i][3] - lines[i][1],
                       (double)lines[i][2] - lines[i][0]);
        ang += angle;
        //寻找竖直直线并根据位置滤除两边的直线
        if(abs(angle) > CV_PI/3
                && lines[i][0] > 4*size.width/10 && lines[i][2] < 6*size.width/10)
            cv::line(disp_lines, cv::Point(lines[i][0], lines[i][1]),
                     cv::Point(lines[i][2], lines[i][3]), cv::Scalar(255, 0 ,0));

    }

HoughLinesP(disp_lines, lines, 80, CV_PI/2, CV_THRESH_OTSU|CV_THRESH_BINARY, 110, 10);//观察disp_lines有几条竖直直线
    imwrite("./aa.jpg",disp_lines);
//    cv::imshow("filename", disp_lines);
//    cv::waitKey(0);

    return a.exec();
}
