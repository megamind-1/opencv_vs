#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat src, dst, gsrc;
int thresholdValue = 127;
int thresholdMax = 255;
int classValue = 2;

void ThresholdDemo(int, void*);

int main(int argc, char** argv)
{
	src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src window", CV_WINDOW_AUTOSIZE);
	imshow("src window", src);

	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	createTrackbar("value", "dst", &thresholdValue, thresholdMax, ThresholdDemo);
	createTrackbar("class", "dst", &classValue, 4, ThresholdDemo);
	ThresholdDemo(0, 0);


	waitKey(0);
	return 0;
}

void ThresholdDemo(int, void*)
{
	cvtColor(src, gsrc, CV_BGR2GRAY);								//必须是灰度图像
	threshold(gsrc, dst, 0, 255, THRESH_TRIANGLE | classValue);		//二值化、反二值化、截断、取零、反取零
	imshow("dst", dst);
}