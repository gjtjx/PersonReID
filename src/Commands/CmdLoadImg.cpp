#include "CmdLoadImg.h"
using namespace std;
using namespace cv;

CCmdLoadImg::CCmdLoadImg(string path, int init_status, shared_ptr<CImage> ptrImg ):CCommand("loadimg",init_status)
{
	src_path = path;
	dstImage = ptrImg;
}

void CCmdLoadImg::execute(void)
{
	try
	{
		switch(getStatus())
		{
		case 0: displayHelp(); break;
		case -1: displayError(); break;
		case 1:
			{
				dstImage->loadImage(src_path);
				dstImage->showImage();
				waitKey();
				break;
			}
		}
	}
	catch(cv::Exception err)
	{
		cout<<err.what()<<endl;
		displayError();
	}
	
}

CCmdLoadImg::~CCmdLoadImg(void){};

void CCmdLoadImg::displayHelp(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"Discription: Load an image into the current image slot"<<endl;
	cout<<"    "<<"Format: loadimage [-PATH]"<<endl;
}

void CCmdLoadImg::displayError()
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Load image failed."<<endl;
	cout<<"    "<<"for more information, please use : loadimage -help"<<endl;
}


CCmdLoadImg::CCmdLoadImg(string sargs, shared_ptr<CImage> ptrImg)
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;
	while(ssargs>>arg) args.push_back(arg);

	if(1==args.size())
	{
		if("-help"==args.front()) 
		{
			setStatus(0);
			src_path = "";
			dstImage = nullptr;
		}
		else
		{
			setStatus(1);
			src_path = args.front();
			dstImage = ptrImg;
		}
	}
	else
	{
		setStatus(-1);
		src_path = "";
		dstImage = nullptr;
	}
}








