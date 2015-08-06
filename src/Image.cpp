#include "Image.h"
using namespace std;
using namespace cv;

void CImage::loadImage(string path)
{
	data = imread("lena_full.jpg");
}

void CImage::showImage(void)
{
	imshow("testwd",data);
}

CImage::~CImage(void){};