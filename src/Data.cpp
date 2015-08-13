#include "Data.h"
using namespace std;
using namespace cv;

CData::~CData(void){}



void CImage::loadImage(string path)
{
	data = imread(path);
}

void CImage::showImage(void)
{
	imshow("testwd",data);
}

CImage::~CImage(void){};

int CImage::getHeight(void)
{
	return data.size().height;
}
int CImage::getWidth(void)
{
	return data.size().width;
}
cv::Mat* CImage::getData(void)
{
	return &data;
}