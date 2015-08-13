#include "CmdLoadImg.h"
using namespace std;
using namespace cv;

CCmdLoadImg::CCmdLoadImg(std::string path, std::string id, int init_status, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("loadimg",init_status)
{
	src_path = path;
	rcs = resources;
	dst_id = id;
}

void CCmdLoadImg::execute(void)
{
	try
	{
		switch(getStatus())
		{
			case 0:
			{
				displayHelp(); 
				break;
			} 
			case -1: 
			{
				displayError(); 
				break;
			}
			case 1:
			{
				auto iter = rcs->find(dst_id);
				if(iter==rcs->end())
				{
					cout<<"    "<<"Added image into storage: "<<dst_id<<endl;
					shared_ptr<CImage> img = make_shared<CImage>();
					img->loadImage(src_path);
					rcs->insert(pair<string,shared_ptr<CImage> > (dst_id,img));
				}
				else
				{
					cout<<"    "<<"Replaced this image with image loaded from file: "<<dst_id<<endl;
					iter->second->loadImage(src_path);
				}
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

void CCmdLoadImg::displayError(int err_num)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Load image failed."<<endl;
	cout<<"    "<<"for more information, please use : loadimg -help"<<endl;
}


CCmdLoadImg::CCmdLoadImg(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("loadimg")
{
	rcs = resources;
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;
	while(ssargs>>arg) args.push_back(arg);
	// cout<<"args.size()"<<args.size()<<endl;
	// cout<<args.front()<<endl;
	// cout<<"ss"<<ssargs.str()<<endl;
	// cout<<"s"<<sargs<<endl;
	if(1==args.size())
	{
		if("-help"==args.front()) 
		{
			setStatus(0);
			src_path = "";
		}
		else
		{
			setStatus(1);
			src_path = args.front();
			dst_id = "src";
		}
	}
	else if(2 == args.size())
	{
		setStatus(1);
		dst_id = args.front();
		src_path = args.back();
	}
	else
	{
		setStatus(-1);
		src_path = "";
	}
}








