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