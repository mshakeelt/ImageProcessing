#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using namespace cv;

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

void dilateImg() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat gray_img, blur_img, canny_img, dilated_img;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	cvtColor(img, gray_img, COLOR_BGR2GRAY);
	GaussianBlur(gray_img, blur_img, Size(3, 3), 3, 0);
	Canny(blur_img, canny_img, 25, 75);
	dilate(canny_img, dilated_img, kernel);
	imshow("img", img);
	imshow("gray", gray_img);
	imshow("blur", blur_img);
	imshow("canny", canny_img);
	imshow("dilated", dilated_img);
	waitKey(0);
	destroyAllWindows();
}

void erodeImg() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat gray_img, blur_img, canny_img, dilated_img, erroded_img;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	cvtColor(img, gray_img, COLOR_BGR2GRAY);
	GaussianBlur(gray_img, blur_img, Size(3, 3), 3, 0);
	Canny(blur_img, canny_img, 25, 75);
	dilate(canny_img, dilated_img, kernel);
	erode(dilated_img, erroded_img, kernel);
	imshow("img", img);
	imshow("gray", gray_img);
	imshow("blur", blur_img);
	imshow("canny", canny_img);
	imshow("dilated", dilated_img);
	imshow("eroded", erroded_img);
	waitKey(0);
	destroyAllWindows();
}

void resizeAndCropImg() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat resizedImgWithProportion, resizedImgWithoutProportion, croppedImg;
	resize(img, resizedImgWithoutProportion, Size(224, 224));
	resize(img, resizedImgWithProportion, Size(), 0.25, 0.25);
	Rect roi(200, 15, 300, 400);
	croppedImg = img(roi);
	imshow("Original", img);
	imshow("Resized Image Without Proportion", resizedImgWithoutProportion);
	imshow("Resized Image With Proportion", resizedImgWithProportion);
	imshow("Cropped", croppedImg);
	cout << "Size of the original image: " << img.size << endl;
	cout << "Channels of the original image: " << img.channels() << endl;
	cout << "Size of the resized image without proportion: " << resizedImgWithoutProportion.size << endl;
	cout << "Channels of the resized image without proportion: " << resizedImgWithoutProportion.channels() << endl;
	cout << "Size of the resized image with proportion: " << resizedImgWithProportion.size << endl;
	cout << "Channels of the resized image with proportion: " << resizedImgWithProportion.channels() << endl;
	waitKey(0);
	destroyAllWindows();
}