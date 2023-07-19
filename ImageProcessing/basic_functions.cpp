#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void readImg() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("Image", img);
	waitKey(0);

}

///////////////  Video  //////////////////////

void readVid() {
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);
	Mat img;
	bool ret;
	while (true) {
		ret = cap.read(img);
		if (ret) {
			imshow("Image", img);
			waitKey(20);
		}
		else {
			break;
		}
	}
}

///////////////  Webcam  //////////////////////

void readCam() {
	VideoCapture cap(0);
	Mat img;
	bool ret;
	while (true)
	{
		ret = cap.read(img);
		if (ret) {
			imshow("Frame", img);
			waitKey(20);
		}
		else {
			break;
		}
	}
}

void imgConversion() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	imshow("original", img);
	imshow("gray", imgGray);
	waitKey(0);
	destroyAllWindows();
}

void blurImg() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat gray_img, blur_image;
	cvtColor(img, gray_img, COLOR_BGR2GRAY);
	GaussianBlur(gray_img, blur_image, Size(7, 7), 10, 10);
	imshow("RGB", img);
	imshow("Gray", gray_img);
	imshow("Blur", blur_image);
	waitKey(0);
	destroyAllWindows();
}

void edgeDetector() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat gray_img, blur_img, canny_img;
	cvtColor(img, gray_img, COLOR_BGR2GRAY);
	GaussianBlur(gray_img, blur_img, Size(3, 3), 5, 0);
	Canny(blur_img, canny_img, 50, 150);
	imshow("Original", img);
	imshow("Gray", gray_img);
	imshow("Blur", blur_img);
	imshow("Canny", canny_img);
	waitKey(0);
	destroyAllWindows();
}