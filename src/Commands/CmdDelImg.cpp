#include "CmdDelImg.h"
#include <iostream>
using namespace std;
using namespace cv;

CCmdDelImg::CCmdDelImg(int init_status, int init_serial, std::vector< std::shared_ptr<CImage> >*resource):CCommand("delimg", init_status)
{
	rcs = resource;
	serial = init_serial;
	
}

CCmdDelImg::CCmdDelImg(std::string sargs, std::vector< std::shared_ptr<CImage> >*resource)
{
	rcs = resource;
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
			try
			{
				serial = stoi(args.front());	
			}catch(exception err)
			{
				setStatus(-1);
				cout<<err.what();
			}
			
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
				if(serial>=(rcs->size()))
				{
					cout<<"    "<<"ERROR: No such resource."<<endl;
				}
				else
				{
					rcs->erase(rcs->begin()+serial);
					cout<<"    "<<"Successfully deleted image"<<endl;
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
	cout<<"    "<<"Discription: Delete an image slot"<<endl;
	cout<<"    "<<"Format: delimg [-number]"<<endl;
}

CCmdDelImg::~CCmdDelImg(void)
{
	// cout<<"ccmddelimg deconstructed"<<endl;
}