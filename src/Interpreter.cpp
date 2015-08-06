#include "Interpreter.h"
using namespace std;

CInterpreter::CInterpreter(CMainframe* thismainframe)
{
	mainframe = thismainframe;
	cmd_table.insert(pair<string,int>("notvalid",0));
	cmd_table.insert(pair<string,int>("loadimage",1));
}

shared_ptr<CCommand> CInterpreter::interpret(string ori_cmd)
{
	stringstream cmdline(ori_cmd);
	string cmd_head;
	string args;
	cmdline>>cmd_head;
	while(cmdline>>args);
	// args = cmdline.str();
	cout<<"cmd_head:"<<cmd_head<<endl;
	cout<<"args:"<<args<<endl;
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
			case 0: 
			{
				this_cmd = CCmdNotValid::create(args);
				break;
			}
			case 1:
			{
				this_cmd = CCmdLoadImage::create(args, mainframe->src_img);
			}
		}
	}

	return this_cmd;
	
}