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
	int getHeight(void);
	int getWidth(void);
	cv::Mat* getData(void);
	~CImage(void);
private:
	cv::Mat data;
};

#endif
