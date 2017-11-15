#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:/pics/source/test2.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat dst;
	//medianBlur(src, dst, 3);						//中值滤波
	//bilateralFilter(src, dst, 15, 100, 3);		//双边滤波
	GaussianBlur(src, dst, Size(15, 15), 3, 3);		//高斯模糊
	
	Mat dst2;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst2, -1, kernel, Point(-1, -1), 0);
	
	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", dst);

	namedWindow("dst2", CV_WINDOW_AUTOSIZE);
	imshow("dst2", dst2);

	waitKey(0);
	return 0;
}