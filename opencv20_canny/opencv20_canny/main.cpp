#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int tValue = 50;
int maxValue = 255;

void CannyDemo(int, void*);
Mat src, gsrc;

int main() {
	src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	
	cvtColor(src, gsrc, CV_BGR2GRAY);											//»Ò¶ÈÍ¼Ïñ
	blur(gsrc, gsrc, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);				//Ä£ºý
	createTrackbar("Threashold value:", "dst", &tValue, maxValue, CannyDemo);
	CannyDemo(0, 0);

	waitKey(0);
	return 0;
}

void CannyDemo(int, void*) {
	Mat output;
	Canny(gsrc, output, tValue, tValue*2, 3, false);							//Canny¼ì²â
	Mat dst;
	dst.create(src.size(), src.type());
	
	src.copyTo(dst, output);
	imshow("dst", ~output);
}
