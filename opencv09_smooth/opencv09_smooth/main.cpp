#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:/pics/source/test5.jpg");
	if (src.empty()) {
		cout << "can't open" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat dst;
	blur(src, dst, Size(1, 29), Point(-1,-1));		//模糊
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	
	Mat dst2;
	GaussianBlur(src, dst2, Size(1, 29), 11, 11);	//高斯模糊
	namedWindow("output2", CV_WINDOW_AUTOSIZE);
	imshow("output2", dst2);

	waitKey(0);
	return 0;
}
