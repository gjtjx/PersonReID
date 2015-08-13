#include "Interpreter.h"
using namespace std;

CInterpreter::CInterpreter(CMainframe* thismainframe)
{
	mainframe = thismainframe;
	cmd_table.insert(pair<string,int>("exit",-2));
	cmd_table.insert(pair<string,int>("notvalid",-1));
	cmd_table.insert(pair<string,int>("help",0));
	cmd_table.insert(pair<string,int>("loadimg",1));
	cmd_table.insert(pair<string,int>("listrcs",2));
	cmd_table.insert(pair<string,int>("addimg",3));
	cmd_table.insert(pair<string,int>("delimg",4));
}

shared_ptr<CCommand> CInterpreter::interpret(string ori_cmd)
{
	auto rcs = &(mainframe->resources);
	stringstream cmdline(ori_cmd);
	string cmd_head;
	string sargs;
	cmdline>>cmd_head;
	sargs = ori_cmd.substr(cmd_head.size());
	// while(cmdline>>sargs);
	// args = cmdline.str();
	// cout<<"cmd_head:"<<cmd_head<<endl;
	// cout<<"args:"<<sargs<<endl;
	// cout<<"cmdline"<<cmdline.str()<<endl;
	auto cmd_search_res = cmd_table.find(cmd_head);

	shared_ptr<CCommand> this_cmd = nullptr;
	// CCommand* ptrCmd=nullptr;
	if( cmd_table.cend() == cmd_search_res )
	{
		auto target = new CCmdNotValid(1);
		this_cmd = make_shared<CCmdNotValid>(*target);
	}
	else
	{
		int cmd_serial = cmd_search_res->second;

		switch(cmd_serial)
		{
			case -2:
			{
				this_cmd = make_shared<CCmdExit>(sargs);
				break;
			}
			case -1: 
			{
				this_cmd = make_shared<CCmdNotValid>(sargs);
				break;
			}
			case 0:
			{
				this_cmd = make_shared<CCmdHelp>(sargs);
				break;
			}
			case 1:
			{
				this_cmd = make_shared<CCmdLoadImg>(sargs,rcs);
				break;
			}
			case 2:
			{
				this_cmd = make_shared<CCmdListRcs>(sargs,rcs);
				break;
			}
			case 3:
			{
				this_cmd = make_shared<CCmdAddImg>(sargs,rcs);
				break;
			}
			case 4:
			{
				this_cmd = make_shared<CCmdDelImg>(sargs,rcs);
				break;
			}
			default:
			{

			}
		}
	}

	return this_cmd;
	
}