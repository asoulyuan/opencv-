#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat src, gray,hist;
	src = imread("D://test//p1.jpg");
	
	if (!src.data)
	{
		cout << "错误" << endl;
		system("pause");
		return -1;
	}
	cvtColor(src, gray, CV_BGR2GRAY);
	imshow("gray", gray);
	const int channels[] = { 0 };//通道数
	const int histSize[] = { 256 };//每个维度划分条目数
	float pranges[] = { 0,255 };
	const float* ranges[] = { pranges };
	calcHist(&gray, 1, 0, Mat(), hist, 1, histSize, ranges, true, false);
	int scale = 2;
	int hist_height = 256;
	Mat hist_img = Mat::zeros(hist_height, hist_height * 2, CV_8UC3);
	double max_val;
	minMaxLoc(hist, 0, &max_val, 0, 0);
	for (int i = 0; i < 256; i++)
	{
		float bin_val = hist.at<float>(i);
		int intensity = cvRound(bin_val * (hist_height / max_val));
		rectangle(hist_img, Point(i * scale, hist_height - 1), Point((i + 1) * scale - 1, hist_height - intensity), Scalar(255, 255, 255));//绘制直方图


	}

	imshow("hist_img", hist_img);
	waitKey(0);
	return 0;

}