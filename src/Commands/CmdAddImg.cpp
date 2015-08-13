#include "CmdAddImg.h"
using namespace std;
using namespace cv;

CCmdAddImg::CCmdAddImg(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("addimg")
{
	rcs = resources;
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;

	while(ssargs>>arg) args.push_back(arg);

	if(args.size()==1)
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


CCmdAddImg::CCmdAddImg(int status,string id, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources):CCommand("addimg",status)
{
	rcs = resources;
	dst_id = id;
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
				if(rcs->size()>=10)
				{
					cout<<"    "<<"Failed to added image, out of space."<<endl;
					break;
				}
				else
				{
					auto iter = rcs->find(dst_id);
					if(iter==rcs->end())
					{
						shared_ptr<CImage> img = make_shared<CImage>();
						rcs->insert(pair<string,shared_ptr<CImage> > (dst_id,img));
						cout<<"    "<<"Successfully added image: "<<dst_id<<endl;
					}
					else
					{
						cout<<"    "<<"Failed to added image, resource id already exists."<<endl;
					}
					
					break;
				}		
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

void CCmdAddImg::displayError(int err_num)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002: Add image failed."<<endl;
	cout<<"    "<<"for more information, please use : listrcs -help"<<endl;
}
