#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat src, dst;
int elementSize = 3;
int maxSize = 21;
void callBackDemo(int, void*);

int main()
{
	src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	createTrackbar("dst size", "dst", &elementSize, maxSize, callBackDemo);
	callBackDemo(0, 0);

	waitKey(0);
	return 0;
}

void callBackDemo(int , void* )
{
	int s = elementSize * 2 + 1;
	Mat element = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	dilate(src, dst, element, Point(-1, -1));
	//erode(src, dst, element, Point(-1, -1));
	imshow("dst", dst);
	return;
}