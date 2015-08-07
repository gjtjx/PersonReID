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