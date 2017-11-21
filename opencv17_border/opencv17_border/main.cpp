#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main() {
	Mat src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	int top = (int) (0.05 * src.rows);
	int bottom = (int) (0.05 * src.rows);
	int left = (int) (0.05 * src.cols);
	int right = (int) (0.05 * src.cols);

	RNG rng(12345);
	int borderType = BORDER_DEFAULT;

	Mat dst;
	int c = 0;
	while (true) {
		c = waitKey(500);
		if ((char)c == 27) {			//ESC
			break;
		}
		if ((char)c == 'r') {
			borderType = BORDER_REPLICATE;
		}
		else if ((char)c == 'w') {
			borderType = BORDER_WRAP;
		}
		else if ((char)c == 'c') {
			borderType = BORDER_CONSTANT;
		}
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		copyMakeBorder(src, dst, top, bottom, left, right, borderType, color);
		imshow("dst", dst);
	}

	waitKey(0);
	return 0;
}