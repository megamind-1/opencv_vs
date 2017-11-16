#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main()
{
	Mat src1 = imread("D:/pics/mine/test1.jpg");
	Mat src2 = imread("D:/pics/mine/test2.jpg");
	if (src1.empty()) {
		cout << "can't open src1!" << endl;
		return -1;
	}
	if (src2.empty()) {
		cout << "can't open src2!" << endl;
		return -1;
	}
	double alpha = 0.5;
	Mat dst;
	if (src1.rows == src2.rows && src1.cols == src2.cols) {
		addWeighted(src1, alpha, src2, (1.0-alpha), 0.0, dst);		//混合
		
		//add(src1, src2, dst, Mat());								//相加
		//multiply(src1, src2, dst, 1.0);							//相乘
		
		namedWindow("dst", CV_WINDOW_AUTOSIZE);
		imshow("dst", dst);
	}
	else {
		printf("could not blend images!");
		return -1;
	}

	waitKey(0);
	return 0;
}