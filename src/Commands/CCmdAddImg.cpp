#include "CCmdAddImg.h"
using namespace std;
using namespace cv;

CCmdAddImg::CCmdAddImg(std::string sargs, std::vector< std::shared_ptr<CImage> >*resource):CCommand("addimg")
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;

	while(ssargs>>arg) args.push_back(arg);

	if(args.size()==0)
	{
		setStatus(1);
	}
	else if(args.size()==1)
	{
		if("-help"==args.front()) 
		{
			setStatus(0);
		}
		else
		{
			setStatus(-1);
		}
	}
	else
	{
		setStatus(-1);
	}

	rcs = resource;
}


CCmdAddImg::CCmdAddImg(int status, std::vector< std::shared_ptr<CImage> >*resource):CCommand("addimg",status)
{
	rcs = resource;
}


void CCmdAddImg::execute(void)
{
	try
	{
		switch(getStatus())
		{
			case 0 :
			{
				displayHelp();
				break;
			}
			case 1:
			{
				CImage* tmp_img = new CImage();
				shared_ptr<CImage> tmp_ptr = make_shared<CImage>(*tmp_img);
				rcs->push_back(tmp_ptr);
				cout<<"    "<<"Successfully added image "<<rcs->size()-1<<endl;
				break;
			}
			default:
			{
				displayError();
				break;
			}
		}
	}catch(exception err)
	{
		cout<<err.what();
	}
}

CCmdAddImg::~CCmdAddImg(void){}

void CCmdAddImg::displayHelp(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"Discription: Add new image into this program."<<endl;
	cout<<"    "<<"Format: addimg (no arguments)"<<endl;
}

void CCmdAddImg::displayError(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Add image failed."<<endl;
	cout<<"    "<<"for more information, please use : listrcs -help"<<endl;
}
