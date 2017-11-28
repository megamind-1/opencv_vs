#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;


int main() {
	Mat src = imread("D:/pics/source/lines.png");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat gsrc;
	cvtColor(src, gsrc, CV_BGR2GRAY);

	Mat dst;

	Canny(src, gsrc, 150, 200);						//ÌáÈ¡±ßÔµ
	cvtColor(gsrc, dst, CV_GRAY2BGR);

	imshow("gsrc", gsrc);

	vector<Vec4f> plines;
	HoughLinesP(gsrc, plines, 1, CV_PI / 180.0, 10, 0, 10);
	Scalar color = Scalar(0, 0, 255);
	for (size_t i = 0; i < plines.size(); i++) {
		Vec4f hline = plines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3, LINE_AA);
	}
	imshow("dst", dst);

	waitKey(0);
	return 0;
}