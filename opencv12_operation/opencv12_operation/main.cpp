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
	//morphologyEx(src, dst, CV_MOP_CLOSE, kernel);		//�ղ���
	//morphologyEx(src, dst, CV_MOP_OPEN, kernel);		//������
	//morphologyEx(src, dst, CV_MOP_GRADIENT, kernel);	//��̬ѧ�ݶ�
	//morphologyEx(src, dst, CV_MOP_TOPHAT, kernel);	//��ñ		src - open
	morphologyEx(src, dst, CV_MOP_BLACKHAT, kernel);	//��ñ		close - src
	imshow("dst", dst);

	waitKey(0);
	return 0;
}