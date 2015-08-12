#ifndef DATA_H
#define DATA_H

#include <string>
#include <opencv2/opencv.hpp>

//---------------------CDATA-----------------//
//---------------所有数据对象的基类------------//
class CData
{
public:
	virtual ~CData(void);
};


//--------------------CImage----------------//
//------------------图像数据成员--------------//
class CImage : public CData
{
public:
	void loadImage(std::string);
	void showImage(void);
	~CImage(void);
	cv::Mat data;
};

#endif
