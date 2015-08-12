#include "CCmdListRcs.h"
using namespace std;
using namespace cv;

CCmdListRcs::CCmdListRcs(std::string sargs, std::shared_ptr<CImage> src, std::shared_ptr<CImage> dst,std::vector< std::shared_ptr<CImage> >resource):CCommand("listrcs")
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

	src_img = src;
	dst_img = dst;
	rcs = resource;
}

CCmdListRcs::CCmdListRcs(int status, std::shared_ptr<CImage> src, std::shared_ptr<CImage> dst,std::vector< std::shared_ptr<CImage> > resource):CCommand("listrcs",status)
{
	src_img = src;
	dst_img = dst;
	rcs = resource;
}

void CCmdListRcs::execute(void)
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
				cout<<"    "<<"src: "<<src_img->data.size().width<<"*"<<src_img->data.size().height<<endl;
				cout<<"    "<<"dst: "<<dst_img->data.size().width<<"*"<<dst_img->data.size().height<<endl;
				int i = 1;
				for(auto picptr: rcs)
				{
					cout<<"    "<<"Picture"<<i++<<": "<<picptr->data.size().width<<"*"<<picptr->data.size().height<<endl;
				}
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

CCmdListRcs::~CCmdListRcs(void){}

void CCmdListRcs::displayHelp(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"Discription: List all the resources loaded into this program."<<endl;
	cout<<"    "<<"Format: loadimage (no arguments)"<<endl;
}

void CCmdListRcs::displayError(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Load image failed."<<endl;
	cout<<"    "<<"for more information, please use : listrcs -help"<<endl;
}