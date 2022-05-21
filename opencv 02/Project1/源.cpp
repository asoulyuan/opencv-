//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <stdio.h>
//
//using namespace std;
//using namespace cv;
//
///** @º¯Êý main */
//int main(int argc, char** argv)
//{
//	Mat src;
//	src = imread("D:\\test\\p1.jpg");
//	if (!src.data)
//	{
//		return -1;
//	}
//
//	vector<Mat> dims;
//	split(src, dims);
//	int histSize = 255;
//	float range[] = { 0,255 };
//	const float* histRange = { range };
//	bool uniform = true;
//	bool accumulate = false;
//	Mat r_hist, g_hist, b_hist;
//	calcHist(&dims[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
//	calcHist(&dims[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
//	calcHist(&dims[2], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
//	int hist_width = 400;
//	int hist_height = 400;
//	int bin_w = cvRound((double)hist_width / histSize);
//	Mat histImage(hist_width, hist_height, CV_8UC3, Scalar(0, 0, 0));
//
//	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
//
//
//	for (int i = 1; i < histSize; i++)
//	{
//		line(histImage, Point(bin_w * (i - 1), hist_height - cvRound(r_hist.at<float>(i - 1))),
//			Point(bin_w * (i), hist_height - cvRound(r_hist.at<float>(i))),
//			Scalar(0, 0, 255), 2, 8, 0);
//		line(histImage, Point(bin_w * (i - 1), hist_height - cvRound(g_hist.at<float>(i - 1))),
//			Point(bin_w * (i), hist_height - cvRound(g_hist.at<float>(i))),
//			Scalar(0, 255, 0), 2, 8, 0);
//		line(histImage, Point(bin_w * (i - 1), hist_height - cvRound(b_hist.at<float>(i - 1))),
//			Point(bin_w * (i), hist_height - cvRound(b_hist.at<float>(i))),
//			Scalar(255, 0, 0), 2, 8, 0);
//	}
//	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
//	imshow("calcHist Demo", histImage);
//	waitKey(0);
//
//}
#include<iostream>
#include<opencv2/opencv.hpp>
#include<stdio.h>
using namespace std;
using namespace cv;
int main()
{
	VideoCapture cap(0);

	double scale = 0.5;


	double i_minH = 0;
	double i_maxH = 20;


	double i_minS = 45;
	double i_maxS = 255;


	double i_minV = 55;
	double i_maxV = 255;
	while (1)
	{
		Mat frame, hsvMat, detectMat;
		cap >> frame;
		Size ResImgSize = Size(frame.cols * scale, frame.rows * scale);
		Mat rFrame = Mat(ResImgSize, frame.type());
		resize(frame, rFrame, ResImgSize, INTER_LINEAR);
		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);
		rFrame.copyTo(detectMat);
		inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);
		imshow("in the range", detectMat);
		imshow("frame", rFrame);
		waitKey(30);


	}


}