#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

Mat src;
void myLine();
void myRectangle();
void myEllipse();
void myCircle();
void myPolygon();
void RandomLineDemo();

int main(int argc, char** argv)
{
	src = imread("D:/pics/source/test6.jpg");
	if (src.empty()) {
		cout << "can't open!" << endl;
		return -1;
	}

	//myLine();
	//myRectangle();
	//myEllipse();
	//myCircle();
	//myPolygon();

	//putText(src, "Hello", Point(10, 50), CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(200, 50, 12), 2, 8);

	//namedWindow("src", CV_WINDOW_AUTOSIZE);
	//imshow("src", src);

	RandomLineDemo();

	waitKey(0);
	return 0;
}

void myLine()
{
	Point p1 = Point(1,1);
	Point p2;
	p2.x = 300;
	p2.y = 300;
	Scalar color = Scalar(0, 255, 0);
	line(src, p1, p2, color, LINE_AA);			//draw line
}

void myRectangle()
{
	Rect rect = Rect(1, 1, 100, 100);
	Scalar color = Scalar(0, 0, 255);
	rectangle(src, rect, color, 2, LINE_8);		//draw rectangle
}

void myEllipse()
{
	Scalar color = Scalar(255, 0, 0);			//draw ellipse
	ellipse(src, Point(src.cols/2, src.rows/2), Size(src.cols/4, src.rows/8), 45, 0, 360, color, 2, LINE_8);
}

void myCircle()
{
	Scalar color = Scalar(0xff, 0xcc, 0x66);	//draw circle
	Point center = Point(src.cols/2-8, src.rows/2);
	circle(src, center, 95, color, 2, 8);
}

void myPolygon()
{
	Point pts[1][5];
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);

	const Point* ppts[] = {pts[0]};
	int n[] = { 5 };
	Scalar color = Scalar(255, 12, 255);
												//fill area
	fillPoly(src, ppts, n, 1, color, 8);
}

void RandomLineDemo()
{
	Mat src2 = Mat::zeros(src.size(), src.type());
	namedWindow("src2", CV_WINDOW_AUTOSIZE);
	RNG rng(12345);
	Point pt1;
	Point pt2;									//draw random line
	for (int i = 0; i < 500000; i++) {
		pt1.x = rng.uniform(0, src2.cols);
		pt2.x = rng.uniform(0, src2.cols);
		pt1.y = rng.uniform(0, src2.rows);
		pt2.y = rng.uniform(0, src2.rows);

		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		waitKey(50);
		line(src2, pt1, pt2, color, 1, 8);
		imshow("src2", src2);

	}
}