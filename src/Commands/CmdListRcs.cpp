#include "CmdListRcs.h"
using namespace std;
using namespace cv;

CCmdListRcs::CCmdListRcs(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("listrcs")
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

	rcs = resources;
}

CCmdListRcs::CCmdListRcs(int status, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("listrcs",status)
{
	rcs = resources;
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
				auto img = rcs->find("src");
				cout<<"    "<<"src: "<<img->second->getWidth()<<"*"<<img->second->getHeight()<<endl;
				img = rcs->find("dst");
				cout<<"    "<<"dst: "<<img->second->getWidth()<<"*"<<img->second->getHeight()<<endl;
				for(auto picptr: *rcs)
				{
					if(picptr.first!="src" && picptr.first!="dst")
					cout<<"    "<<picptr.first<<": "<<picptr.second->getWidth()<<"*"<<picptr.second->getHeight()<<endl;
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

void CCmdListRcs::displayError(int err_num)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Load image failed."<<endl;
	cout<<"    "<<"for more information, please use : listrcs -help"<<endl;
}