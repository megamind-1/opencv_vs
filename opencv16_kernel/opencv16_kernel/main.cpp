#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat src, dst, dst2;

int main(int argc, char** argv) {
	src = imread("D:/pics/source/test3.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	//Mat kernelX = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);		//X方向 Sobel robert(1, 0, 0, -1)
	//filter2D(src, dst, -1, kernelX, Point(-1, -1), 0.0);
	//
	//Mat kernelY = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);		//Y方向 Sobel robert(0, 1, -1, 0)
	//filter2D(src, dst2, -1, kernelY, Point(-1, -1), 0.0);

	////拉普拉斯算子
	//Mat lplsdst;
	//Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	//filter2D(src, lplsdst, -1, kernel, Point(-1, -1), 0.0);

	//namedWindow("lplsdst", CV_WINDOW_AUTOSIZE);
	//imshow("lplsdst", lplsdst);

	int index = 0;
	int c = 0;
	int kSize = 3;
	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	while (true) {									//逐渐加深模糊
		c = waitKey(500);
		if ((char)c == 27) {					//ESC
			break;
		}
		kSize = 4 + (index % 8) * 2 + 1;
		Mat kernel = Mat::ones(Size(kSize, kSize), CV_32F) / (float) (kSize * kSize);
		filter2D(src, dst, -1, kernel, Point(-1, -1));
		index++;
		imshow("dst", dst);
		
	}

	/*namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", dst);

	namedWindow("dst2", CV_WINDOW_AUTOSIZE);
	imshow("dst2", dst2);*/

	waitKey(0);
	return 0;
}