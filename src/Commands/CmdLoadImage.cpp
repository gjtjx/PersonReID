#include "CmdLoadImage.h"
using namespace std;
using namespace cv;
CCmdLoadImage::CCmdLoadImage(string path , shared_ptr<CImage> ptrImage , int init_status)
{
	name = "loadimage";
	status = init_status;
	src_path = path;
	dstImage = ptrImage;
}

void CCmdLoadImage::execute(void)
{
	try
	{
		switch(status)
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

CCmdLoadImage::~CCmdLoadImage(void){};

void CCmdLoadImage::displayHelp(void)
{
	cout<<name<<endl;
	cout<<"Discription: Load an image into the current image slot"<<endl;
	cout<<"Format: loadimage [-PATH]"<<endl;
}

void CCmdLoadImage::displayError()
{
	cout<<name<<endl;
	cout<<"ERROR 0x002: Load image failed."<<endl;
	cout<<"for more information, please use : loadimage -help"<<endl;
}


shared_ptr<CCmdLoadImage> CCmdLoadImage::create(string sargs, shared_ptr<CImage> ptrImg)
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;
	shared_ptr<CCmdLoadImage> this_cmd;
	while(ssargs>>arg) args.push_back(arg);

	if(1==args.size())
	{
		if("-help"==args.front()) this_cmd = shared_ptr<CCmdLoadImage>(new CCmdLoadImage("",nullptr,0));
		else this_cmd = shared_ptr<CCmdLoadImage>(new CCmdLoadImage(args.front(),ptrImg,1));
	}
	else
	{
		this_cmd = shared_ptr<CCmdLoadImage>(new CCmdLoadImage("",nullptr,-1));
	}
	return this_cmd;
}