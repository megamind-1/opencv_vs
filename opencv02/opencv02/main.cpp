#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
int main(int argc, char** argv)
{
	Mat src, dst;
	src = imread("D:/pics/source/test6.jpg");					//读取图片
	if (!src.data)
	{
		printf("could not open!");
		return -1;
	}
	namedWindow("win1", CV_WINDOW_AUTOSIZE);					//新建一个窗口
	imshow("win1", src);										//打开原图片

	int cols = (src.cols - 1) * src.channels();
	int offsetX = src.channels();
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());
	/*
	for (int r = 1; r < rows-1; r++) {
		const uchar* current = src.ptr<uchar>(r);
		const uchar* previous = src.ptr<uchar>(r-1);
		const uchar* next = src.ptr<uchar>(r+1);
		uchar* output = dst.ptr<uchar>(r);
		for (int c = offsetX; c < cols; c++) {
			output[c] = saturate_cast<uchar>(current[c] * 5 - (current[c - offsetX]+ current[c + offsetX] + previous[c] + next[c]));
		}
	}
	*/
	double t = getTickCount();
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	for (int i = 0; i < 100; i++) {
		filter2D(src, dst, src.depth(), kernel);					//处理图片
	}
	double t2 = (getTickCount() - t) / getTickFrequency();
	printf("teme: %.3lf\n", t2);

	namedWindow("changed", CV_WINDOW_AUTOSIZE);
	imshow("changed", dst);
	imwrite("D:/pics/finish/test1.jpg", dst);
	waitKey(0);
	return 0;
}