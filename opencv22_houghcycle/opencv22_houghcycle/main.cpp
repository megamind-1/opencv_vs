#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main() {
	Mat src = imread("D:/pics/source/testx.jpg");
	if (src.empty()) {
		cout << "can't open" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	
	Mat msrc, dst;
	medianBlur(src, msrc, 3);							//÷–÷µ¬À≤®
	cvtColor(msrc, msrc, CV_BGR2GRAY);

	vector<Vec3f> pcircle;								//ªÙ∑Ú‘≤ºÏ≤‚
	HoughCircles(msrc, pcircle, CV_HOUGH_GRADIENT, 1, 10, 100, 30, 5, 50);

	src.copyTo(dst);
	for (size_t i = 0; i < pcircle.size(); i++) {
		Vec3f cc = pcircle[i];
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(0, 0, 255), 2, LINE_AA);
		circle(dst, Point(cc[0], cc[1]), 2, Scalar(0xff, 0x66, 0xcc), 2, LINE_AA);
	}
	imshow("dst", dst);

	waitKey(0);
	return 0;
}