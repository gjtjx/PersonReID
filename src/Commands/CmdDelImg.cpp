#include "CmdDelImg.h"
#include <iostream>
using namespace std;
using namespace cv;

CCmdDelImg::CCmdDelImg(int init_status, std::string id, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("delimg", init_status)
{
	rcs = resources;
	dst_id = id;
	
}

CCmdDelImg::CCmdDelImg(std::string sargs,std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("delimg")
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
		}
		else
		{
			setStatus(1);
			dst_id = args.front();
			
		}
	}
	else
	{
		setStatus(-1);
	}
}

void CCmdDelImg::execute(void)
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
			case 1:
			{
				auto img = rcs->find(dst_id);
				if(img==rcs->end())
				{
					cout<<"    "<<"ERROR: No such resource."<<endl;
				}
				else if( dst_id =="src" || dst_id=="dst")
				{
					cout<<"    "<<"ERROR: Can not delete built in image."<<endl;
				}
				else
				{
					rcs->erase(img);
					cout<<"    "<<"Successfully deleted image: "<<dst_id<<endl;
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
		displayError();
		cout<<err.what();
	}
}

void CCmdDelImg::displayError(int err_num)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Delete image failed."<<endl;
	cout<<"    "<<"for more information, please use : delimg -help"<<endl;
}

void CCmdDelImg::displayHelp()
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"Discription: Delete an image "<<endl;
	cout<<"    "<<"Format: delimg [id]"<<endl;
}

CCmdDelImg::~CCmdDelImg(void)
{
	// cout<<"ccmddelimg deconstructed"<<endl;
}