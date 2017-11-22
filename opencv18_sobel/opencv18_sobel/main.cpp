#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat dst;
	GaussianBlur(src, dst, Size(3, 3), 0, 0);

	Mat graydst;
	cvtColor(dst, graydst, CV_BGR2GRAY);

	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", graydst);

	Mat xgrad, ygrad;
	Sobel(graydst, ygrad, CV_16S, 0, 1, 3);			//Ë÷±´¶ûËã·¨
	Sobel(graydst, xgrad, CV_16S, 1, 0, 3);			//¼ÆËãÍ¼ÐÎµÄ±ßÔµ
	//Scharr(graydst, ygrad, CV_16S, 0, 1);
	//Scharr(graydst, xgrad, CV_16S, 1, 0);
	convertScaleAbs(xgrad, xgrad);
	convertScaleAbs(ygrad, ygrad);
	//imshow("x", xgrad);
	//imshow("y", ygrad);

	Mat xygrad = Mat(xgrad.size(), xgrad.type());
	int width = xgrad.cols;
	int height = ygrad.rows;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int xg = xgrad.at<uchar>(i, j);
			int yg = ygrad.at<uchar>(i, j);
			int xxyy = sqrt(xg * xg + yg * yg);
			xygrad.at<uchar>(i, j) = saturate_cast<uchar>(xxyy);
		}
	}

	//addWeighted(xgrad, 0.5, ygrad, 0.5, 0, xygrad);
	imshow("xy", xygrad);

	waitKey(0);
	return 0;
}