#include "iostream"
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat src = imread("lena.jpg"); 
	Mat dst1,dst2;
	cvtColor(src, src, COLOR_BGR2GRAY);//转换为灰度图
	threshold(src, dst1, 100, 255, THRESH_BINARY);//二值化 threshold(输入图像，输出图像，阈值，最大值，阈值类型)
	imshow("threshold", dst1);
	adaptiveThreshold(src, dst2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 10);//自适应二值化 adaptiveThreshold(输入图像，输出图像，最大值，自适应方法，阈值类型，blockSize，常数)
	imshow("adaptiveThreshold", dst2);
	waitKey();
	return 0;
}