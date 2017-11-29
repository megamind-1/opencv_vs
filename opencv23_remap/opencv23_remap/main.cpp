#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;

Mat src, dst, mapx, mapy;
int index = 0;

void update_map(void);

int main() {
	src = imread("D:/pics/source/test1.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}
	namedWindow("src", CV_WINDOW_AUTOSIZE);
	imshow("src", src);

	mapx.create(src.size(), CV_32FC1);
	mapy.create(src.size(), CV_32FC1);

	int c = 0;
	while (true) {
		c = waitKey(500);
		index = c % 4;
		if ((char)c == 27) {
			break;
		}

		update_map();
		remap(src, dst, mapx, mapy, INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 255, 255));
	
		namedWindow("dst", CV_WINDOW_AUTOSIZE);
		imshow("dst", dst);
	}

	waitKey(0);
	return 0;
}

void update_map(void) {							//映射
	for (int r = 0; r < src.rows; r++) {
		for (int c = 0; c < src.cols; c++) {
			switch (index) {
			case 0:								//缩小
				if (c >= (src.cols * 0.25) && c <= (src.cols * 0.75) && r >= (src.rows*0.25) && r <= (src.rows*0.75)) {
					mapx.at<float>(r, c) = (c - src.cols * 0.25) * 2;
					mapy.at<float>(r, c) = (r - src.rows * 0.25) * 2;
				}
				else {
					mapx.at<float>(r, c) = 0;
					mapy.at<float>(r, c) = 0;
				}
				break;
			case 1:								//左右翻转
				mapx.at<float>(r, c) = (src.cols - c - 1);
				mapy.at<float>(r, c) = r;
				break;
			case 2:								//上下翻转
				mapx.at<float>(r, c) = c;
				mapy.at<float>(r, c) = (src.rows - r - 1);
				break;
			case 3:								//旋转
				mapx.at<float>(r, c) = (src.cols - c - 1);
				mapy.at<float>(r, c) = (src.rows - r - 1);
				break;
			}
		}
	}
}