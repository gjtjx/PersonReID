#include "CmdNotValid.h"
using namespace std;

CCmdNotValid::CCmdNotValid(int init_status)
{
	name = "notvalid";
	status = init_status;
}

void CCmdNotValid::execute()
{
	cout<<"error 0x001: Not a valid command."<<endl;
}

shared_ptr<CCmdNotValid> CCmdNotValid::create(string sargs)
{
	vector<string> args;
	stringstream ssargs(sargs);
	string arg;
	shared_ptr<CCmdNotValid> this_cmd;
	CCmdNotValid* ptrCmd=nullptr;
	while(ssargs>>arg) args.push_back(arg);

	if(args.size()>=2)
	{
		this_cmd = make_shared<CCmdNotValid>(new CCmdNotValid(-1));
	}
	else if( 0==args.size()) 
	{
		this_cmd = make_shared<CCmdNotValid>(new CCmdNotValid(1));
	}
	else if(args.front()=="-help")
	{
		this_cmd = make_shared<CCmdNotValid>(new CCmdNotValid(0));
	}
	else
	{
		this_cmd = make_shared<CCmdNotValid>(new CCmdNotValid(-1));
	}
	return this_cmd;
}