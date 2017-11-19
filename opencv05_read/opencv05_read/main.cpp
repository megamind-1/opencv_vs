#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:/pics/source/test.jpg");
	if(src.empty())
	{
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);
	
	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	/*
	int h = gray_src.rows;
	int w = gray_src.cols;
	

	for (int r = 0; r < h; r++) {
		for (int c = 0; c < w; c++) {
			int gray = gray_src.at<uchar>(r,c);			//¶ÁÈ¡»Ò¶ÈÏñËØ
			gray_src.at<uchar>(r, c) = 25 - gray;
		}
	}
	*/
	//namedWindow("gray_src", CV_WINDOW_AUTOSIZE);
	//imshow("gray_src", gray_src);
	
	Mat dst;
	dst.create(src.size(), src.type());
	int h = src.rows;
	int w = src.cols;
	int nc = src.channels();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (nc == 1) {
				int gray = src.at<uchar>(i, j);			//¶ÁÈ¡»Ò¶ÈÏñËØ
				dst.at<uchar>(i, j) = 255 - gray;
			}
			else if (nc == 3) {							//¶ÁĞ´rgbÏñËØ
				int b = src.at<Vec3b>(i, j)[0];
				int g = src.at<Vec3b>(i, j)[1];
				int r = src.at<Vec3b>(i, j)[2];
				dst.at<Vec3b>(i, j)[0] = b;
				dst.at<Vec3b>(i, j)[1] = g;
				dst.at<Vec3b>(i, j)[2] = r;

				gray_src.at<uchar>(i, j) = min(r, min(b, g));
			}
		}
	}
	//bitwise_not(src,dst);
	imshow("bgr", gray_src);
	waitKey(0);
	return 0;
}