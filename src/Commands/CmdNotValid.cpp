#include "CmdNotValid.h"
using namespace std;

CCmdNotValid::CCmdNotValid(int init_status):CCommand("notvalid",init_status){}

void CCmdNotValid::execute()
{
	cout<<"    "<<"ERROR 0x001: Not a valid command."<<endl;
}

CCmdNotValid::~CCmdNotValid(void){};

CCmdNotValid::CCmdNotValid(string sargs):CCommand("notvalid")
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;

	while(ssargs>>arg) args.push_back(arg);

	if(args.size()>=2)
	{
		setStatus(-1);
	}
	else if( 0==args.size()) 
	{
		setStatus(1);
	}
	else if(args.front()=="-help")
	{
		setStatus(0);
	}
	else
	{
		setStatus(-1);
	}
}

void CCmdNotValid::displayHelp(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"this is a notvalid help"<<endl;
}

void CCmdNotValid::displayError(void)
{
	cout<<"    "<<getName()<<endl;
	cout<<"    "<<"this is a notvalid error"<<endl;
}