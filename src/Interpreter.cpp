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
}

shared_ptr<CCommand> CInterpreter::interpret(string ori_cmd)
{
	stringstream cmdline(ori_cmd);
	string cmd_head;
	string sargs;
	cmdline>>cmd_head;
	while(cmdline>>sargs);
	// args = cmdline.str();
	// cout<<"cmd_head:"<<cmd_head<<endl;
	// cout<<"args:"<<args<<endl;
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
				CCmdExit* tmp_cmd = new CCmdExit(sargs);
				this_cmd = make_shared<CCmdExit>(*tmp_cmd);
				break;
			}
			case -1: 
			{
				CCmdNotValid* tmp_cmd = new CCmdNotValid(sargs);
				this_cmd = make_shared<CCmdNotValid>(*tmp_cmd);
				break;
			}
			case 0:
			{
				CCmdHelp* tmp_cmd = new CCmdHelp(sargs);
				this_cmd = make_shared<CCmdHelp>(*tmp_cmd);
				break;
			}
			case 1:
			{
				CCmdLoadImg* tmp_cmd = new CCmdLoadImg(sargs,mainframe->src_img);
				this_cmd = make_shared<CCmdLoadImg>(*tmp_cmd);
				break;
			}
			case 2:
			{
				CCmdListRcs* tmp_cmd = new CCmdListRcs(sargs,mainframe->src_img,mainframe->dst_img,&mainframe->resources);
				this_cmd = make_shared<CCmdListRcs>(*tmp_cmd);
				break;
			}
			case 3:
			{
				CCmdAddImg* tmp_cmd = new CCmdAddImg(sargs,&mainframe->resources);
				this_cmd = make_shared<CCmdAddImg>(*tmp_cmd);
			}
			default:
			{

			}
		}
	}

	return this_cmd;
	
}