#include "CmdNotValid.h"
using namespace std;

CCmdNotValid::CCmdNotValid(void):name("NotValid"){}

void CCmdNotValid::execute()
{
	cout<<"error 0x001: Not a valid command."<<endl;
}

shared_ptr<CCommand> CCmdNotValid::create(std::string s)
{
	
}