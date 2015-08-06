#include "CmdLoadImage.h"
using namespace std;

CCmdLoadImage::CCmdLoadImage(string path , CImage* ptrImage , bool ishelp):name("loadimage")
{
	help_flag = ishelp;
	src_path = path;
	dstImage = ptrImage;
}

void CCmdLoadImage::execute(void)
{
	if(help_flag) 
	{
		displayHelp();
	}
	else
	{
		dstImage->loadImage(src_path);
	}
}

CCmdLoadImage::~CCmdLoadImage(void){};

void CCmdLoadImage::displayHelp(void)
{
	cout<<name<<endl;
	cout<<"Discription: Load an image into the current image slot"<<endl;
	cout<<"Format: loadimage [-PATH]"<<endl;
}