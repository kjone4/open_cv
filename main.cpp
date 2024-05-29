#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;	

void on_mouse(int event, int x, int y, int flags, void*);
Point ptOld;
Mat img, kk;
int main() {
    img = Mat(Size(700, 500), CV_8UC3, Scalar(255, 255, 255));

	line(img, Point(500, 0), Point(500, img.cols), Scalar(0, 0, 0), 3);
	line(img, Point(0, 0), Point(img.cols, 0), Scalar(0, 0, 0), 3);
	line(img, Point(0, 0), Point(0, img.rows), Scalar(0, 0, 0), 3);
	line(img, Point(0, img.rows), Point(img.cols, img.rows), Scalar(0, 0, 0), 3);
	line(img, Point(img.cols, 0), Point(img.cols, img.rows), Scalar(0, 0, 0), 3);
	for (int i = 0; i < img.cols; i += 100) {
		line(img, Point(img.rows, i), Point(img.cols, i), Scalar(0, 0, 0), 3);
	}
	
	putText(img, "Save", Point(520, 65), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 0), 3);
	putText(img, "Load", Point(520, 165), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 0), 3);
	putText(img, "Clear", Point(520, 265), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 0), 3);
	putText(img, "Run", Point(520, 365), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 0), 3);
	putText(img, "Exit", Point(520, 465), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 0), 3);
	img.copyTo(kk);
	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey();
	return 0;
}
void on_mouse(int event, int x, int y, int flags, void*) {
	Rect number(Point(0, 0), Point(499, 499));
	Rect clear(Point(500, 200), Point(700, 300));
	switch (event) {
	case EVENT_LBUTTONDOWN:
		if (number.contains(Point(x, y))) {
			ptOld = Point(x, y);
		}
		else if (clear.contains(Point(x, y))) {
			rectangle(img, Rect(1, 1, 499, 499), Scalar(255, 255, 255));
		}
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON && number.contains(Point(x, y))) {

			line(img, ptOld, Point(x, y), Scalar(0, 0, 0), 5);
			imshow("img", img);
			ptOld = Point(x, y);
		}
		break;
	default:
		break;
	}
}

//저장시 학번끝 두자리, 인식한 숫자, 숫자의 번호.jpg 전부 두자리