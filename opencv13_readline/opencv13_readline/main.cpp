#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{
	Mat src;
	src = imread("D:/pics/source/test1.jpg");				//�����ɫͼ��
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);					//תΪ�Ҷ�ͼ��
	namedWindow("gray", CV_WINDOW_AUTOSIZE);
	imshow("gray", gray_src);

	Mat binimg;												//תΪ��Ԫ�ṹ
	adaptiveThreshold(gray_src, binimg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	namedWindow("bin", CV_WINDOW_AUTOSIZE);
	imshow("bin", binimg);
	//imwrite("D:/pics/source/gray3.jpg", binimg);

															//ˮƽ�ṹԪ��
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols/16,	1), Point(-1, -1));
															//��ֱ�ṹԪ��
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows/16), Point(-1, -1));

	Mat temp;
	Mat dst;
	erode(binimg, temp, vline);								//��ʴ
	dilate(temp, dst, vline);								//����
	bitwise_not(dst, dst);									//��ɰ�ɫ
	imshow("temp", dst);

	waitKey(0);
	return 0;
}