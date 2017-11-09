#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("D:/pics/source/test5.jpg");
	if (src.empty())
	{
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("in", CV_WINDOW_AUTOSIZE);
	imshow("in", src);

	Mat dst;
	//dst = Mat(src.size(), src.type());
	//dst = Scalar(127, 0, 255);
	//dst = src.clone();
	//src.copyTo(dst);
	namedWindow("out", CV_WINDOW_AUTOSIZE);

	cvtColor(src, dst, CV_BGR2GRAY);
	cout << "src.channels=" << src.channels() << endl;
	cout << "dst.channels=" << dst.channels() << endl;

	int col = dst.cols;
	int row = dst.rows;

	printf("dst.cols=%d,dst.rows=%d\n", col, row);

	const uchar* firstRow = dst.ptr<uchar>(0);
	printf("dst.ptr=%d\n", *firstRow);

	//Mat M(100, 100, CV_8UC1, Scalar(127));
	//cout << "M=" << endl << M << endl;

	//Mat m1;
	//m1.create(src.size(), src.type());
	//m1 = Scalar(0, 0, 255);

	Mat m2 = Mat::eye(2, 2, CV_8UC1);

	cout << "m2=" << endl << m2 << endl;


	//Mat kernel = (Mat_<float>(3, 3) << 0, -1 ,0 ,-1 ,5 ,-1 ,0 ,-1 ,0);
	//filter2D(src, dst, -1, kernel);

	imshow("out", m2);

	waitKey(0);
	return 0;
}