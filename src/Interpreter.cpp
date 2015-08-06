#include "Interpreter.h"
using namespace std;

CInterpreter::CInterpreter(CMainframe* thismainframe)
{
	mainframe = thismainframe;
	cmd_table.insert({"notvalid",0});
	cmd_table.insert({"loadimage",1});
}

shared_ptr<CCommand> CInterpreter::interpret(string ori_cmd)
{
	stringstream cmdline(ori_cmd);
	string cmd_head;
	cmdline>>cmd_head;

	auto cmd_search_res = cmd_table.find(cmd_head);

	shared_ptr<CCommand> this_cmd = nullptr;

	if( cmd_table.cend() == cmd_search_res )
	{
		this_cmd = make_shared<CCommand> ();
	}
	else
	{
		int cmd_serial = cmd_search_res->second;

		switch(cmd_serial)
		{
			case 0: 
			{
				this_cmd = make_shared<CCmdNotValid> (); 
				break;
			}
			case 1:
			{
				string arg1;
				cmdline>>arg1;
				if(arg1=="-help") 
				{
					this_cmd = make_shared<CCmdLoadImage>("",nullptr,true);
				}
				else
				{
					
				}
				
				break;
			}
		}
	}

	return this_cmd;
	
}