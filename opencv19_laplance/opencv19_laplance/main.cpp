#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main() {
	Mat src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
													//转化为灰度图像
	Mat gsrc, dst, lplc;
	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	cvtColor(dst, gsrc, CV_BGR2GRAY);
													//拉普拉斯算法
	Laplacian(gsrc, lplc, CV_16S, 3);
	convertScaleAbs(lplc, lplc);
													//二值化输出
	threshold(lplc, lplc, 0, 255, THRESH_OTSU | THRESH_BINARY);
	imshow("lplc", lplc);


	waitKey(0);
	return 0;
}