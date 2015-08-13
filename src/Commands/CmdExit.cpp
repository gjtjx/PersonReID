#include "CmdExit.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

CCmdExit::CCmdExit(int init_status,string s):CCommand("exit",init_status)
{
	msg = s;
}

CCmdExit::CCmdExit(string sargs):CCommand("exit")
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;

	while(ssargs>>arg) args.push_back(arg);

	if(0==args.size())
	{
		setStatus(1);
	}
	else if(1==args.size())
	{
		msg = arg.front();
		setStatus(0);
	}
	else
	{
		setStatus(-1);
	}
}

CCmdExit::~CCmdExit(){}

void CCmdExit::execute()
{
	try
	{
		switch(getStatus())
		{
			case 1: 
			{
				cout<<"----------------------------BYE----------------------------"<<endl;
				break;
			}
			case 0:
			{
				displayHelp();
				cout<<"----------------------------BYE----------------------------"<<endl;
				break;
			}
			case -1:
			{
				displayError();
				cout<<"----------------------------BYE----------------------------"<<endl;
				break;
			}
			default:
			{
				
				cout<<"----------------------------BYE----------------------------"<<endl;
				break;
			}
		}
	}catch(exception err)
	{
		cout<<err.what();
	}
}

void CCmdExit::displayHelp(void)
{
	cout<<"    "<<msg<<endl;
}

void CCmdExit::displayError(int err_num)
{
	cout<<"    "<<"ERROR 0x002 Format not correct."<<endl;
}
