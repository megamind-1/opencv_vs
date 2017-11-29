#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat src, dst, gsrc;

int main() {
	src = imread("D:/pics/source/testl.jpg");
	if(src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);

	cvtColor(src, gsrc, CV_BGR2GRAY);
	equalizeHist(gsrc, dst);					//直方图均衡化

	imshow("src", gsrc);
	imshow("dst", dst);

	waitKey(0);
	return -1;
}