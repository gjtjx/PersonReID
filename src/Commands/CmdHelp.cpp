#include <iostream>
#include "CmdHelp.h"
#include <vector>
#include <sstream>
using namespace std;

CCmdHelp::CCmdHelp(int init_status):CCommand("help", init_status){}

CCmdHelp::CCmdHelp(string sargs):CCommand("help")
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;

	while(ssargs>>arg) args.push_back(arg);

	if(args.size()==0)
	{
		setStatus(0);
	}
	else if(args.size()==1)
	{
		int init_status=-1;
		try
		{
			init_status = stoi(args.front());
		}catch(exception err)
		{
			cout<<err.what()<<endl;
			setStatus(-1);
		}
		setStatus(init_status);
	}
	else
	{
		setStatus(-1);
	}
}

void CCmdHelp::execute(void)
{
	try
	{
		switch(getStatus())
		{
			case -1: displayError(); break;
			case 0: displayHelp(); break;
			default: displayCmdhelp(getStatus());
		}
	}catch(exception err)
	{
		cout<<err.what();
	}
}


CCmdHelp::~CCmdHelp(void){}

void CCmdHelp::displayHelp(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"this is the general help message."<<endl;
}

void CCmdHelp::displayError(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"ERROR 0x002 Format not correct."<<endl;
}

void CCmdHelp::displayCmdhelp(int cmd_serial)
{
	cout<<"    "<<"this is help message "<<cmd_serial<<endl;
	
}
