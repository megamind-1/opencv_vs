#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("D:/pics/source/test3.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
													//上采样
	Mat dst;
	pyrUp(src, dst, Size(src.cols * 2, src.rows * 2));
	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", dst);
													//降采样
	Mat dst2;
	pyrDown(src, dst2, Size(src.cols / 2, src.rows / 2));
	namedWindow("dst2", CV_WINDOW_AUTOSIZE);
	imshow("dst2", dst2);
													//DOG-高斯不同
	Mat gsrc, gdst, gdst2, finalImage;
	cvtColor(src, gsrc, CV_BGR2GRAY);
	GaussianBlur(gsrc, gdst, Size(5, 5), 0, 0);
	GaussianBlur(gdst, gdst2, Size(5, 5), 0, 0);
	subtract(gdst, gdst2, finalImage, Mat());		//相减
													//归一化显示
	normalize(finalImage, finalImage, 255, 0, NORM_MINMAX);
	namedWindow("final", CV_WINDOW_AUTOSIZE);
	imshow("final", finalImage);


	waitKey(0);
	return 0;
}
