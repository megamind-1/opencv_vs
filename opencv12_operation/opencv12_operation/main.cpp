#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

uint main()
{
	Mat src = imread("D:/pics/source/test2.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}

	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	Mat dst;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7), Point(-1, -1));
	//morphologyEx(src, dst, CV_MOP_CLOSE, kernel);		//闭操作
	//morphologyEx(src, dst, CV_MOP_OPEN, kernel);		//开操作
	//morphologyEx(src, dst, CV_MOP_GRADIENT, kernel);	//形态学梯度
	//morphologyEx(src, dst, CV_MOP_TOPHAT, kernel);	//顶帽		src - open
	morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel);	//黑帽		close - src
	imshow("dst", dst);

	waitKey(0);
	return 0;
}