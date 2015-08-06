#ifndef IMAGE_H
#define IMAGE_H

#include "Common.h"
#include <string>
#include <opencv2/opencv.hpp>

class CImage : public CData
{
public:
	void loadImage(std::string);
private:
	cv::Mat data;
};

#endif
