#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:/pics/source/test2.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	cvtColor(src, src, CV_BGR2GRAY);				//bgr->gray

	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	int height = src.rows;
	int width = src.cols;
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat mm;
	src.convertTo(mm, CV_32F);
	float alpha = 1.2;
	float beta = 30;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (src.channels() == 3) {
				float r = mm.at<Vec3f>(i, j)[2];
				float b = mm.at<Vec3f>(i, j)[0];
				float g = mm.at<Vec3f>(i, j)[1];
				//light light
				dst.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(b * alpha + beta);
				dst.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(g * alpha + beta);
				dst.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(r * alpha + beta);
			}
			else if (src.channels() == 1) {
				float gray = src.at<uchar>(i, j);
				dst.at<uchar>(i, j) = saturate_cast<uchar>(gray * alpha + beta);
			}
		}
	}

	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}