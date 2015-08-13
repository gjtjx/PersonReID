#include "CmdSaveImg.h"
using namespace std;
using namespace cv;

CCmdSaveImg::CCmdSaveImg(std::string path, std::string id, int init_status, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("loadimg",init_status)
{
	src_path = path;
	rcs = resources;
	dst_id = id;
}

void CCmdSaveImg::execute(void)
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
					cout<<"    "<<"No such resource: "<<dst_id<<endl;
				}
				else
				{
					cout<<"    "<<"Saved image "<< dst_id<<" to "<<src_path<<endl;
					iter->second->saveImage(src_path);
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

CCmdSaveImg::~CCmdSaveImg(void){};

void CCmdSaveImg::displayHelp(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"Discription: Save an image in storage."<<endl;
	cout<<"    "<<"Format: saveimg [-id] [-PATH]"<<endl;
}

void CCmdSaveImg::displayError(int err_num)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR: Save image failed."<<endl;
	cout<<"    "<<"for more information, please use : saveimg -help"<<endl;
}


CCmdSaveImg::CCmdSaveImg(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("loadimg")
{
	rcs = resources;
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
		}
		else
		{
			setStatus(1);
			src_path = args.front();
			dst_id = "dst";
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








