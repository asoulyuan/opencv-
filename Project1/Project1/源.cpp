#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("D:\\test\\01.jpg");  //����Լ�ͼ���·�� 
    imshow("��ʾͼ��", image);
    waitKey(0);
    return 0;
}
