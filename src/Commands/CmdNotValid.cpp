#include "CmdNotValid.h"
using namespace std;

CCmdNotValid::CCmdNotValid(int init_status)
{
	name = "notvalid";
	status = init_status;
}

void CCmdNotValid::execute()
{
	cout<<"    "<<"ERROR 0x001: Not a valid command."<<endl;
}

CCmdNotValid::~CCmdNotValid(void){};

shared_ptr<CCmdNotValid> CCmdNotValid::create(string sargs)
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;
	shared_ptr<CCmdNotValid> this_cmd;

	while(ssargs>>arg) args.push_back(arg);

	if(args.size()>=2)
	{
		auto target = new CCmdNotValid(-1);
		this_cmd = make_shared<CCmdNotValid>(*target);
	}
	else if( 0==args.size()) 
	{
		auto target = new CCmdNotValid(1);
		this_cmd = make_shared<CCmdNotValid>(*target);
	}
	else if(args.front()=="-help")
	{
		auto target = new CCmdNotValid(0);
		this_cmd = make_shared<CCmdNotValid>(*target);
	}
	else
	{
		auto target = new CCmdNotValid(-1);
		this_cmd = make_shared<CCmdNotValid>(*target);
	}
	return this_cmd;
}

void CCmdNotValid::displayHelp(void)
{
	cout<<"    "<<name<<endl;
	cout<<"    "<<"this is a notvalid help"<<endl;
}

void CCmdNotValid::displayError(void)
{
	cout<<"    "<<name<<endl;
	cout<<"    "<<"this is a notvalid error"<<endl;
}