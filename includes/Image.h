#ifndef IMAGE_H
#define IMAGE_H

#include "Data.h"
#include <string>
#include <opencv2/opencv.hpp>

class CImage : public CData
{
public:
	void loadImage(std::string);
	void showImage(void);
	~CImage(void);
private:
	cv::Mat data;
};

#endif
