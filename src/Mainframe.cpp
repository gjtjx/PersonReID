#include "Mainframe.h"
using namespace std;

void CMainframe::Run(void)
{
	string lastCmdName = "";
	CInterpreter interpreter(this);
	while("Exit" != lastCmdName)
	{
		cout<<"PersonReID>>";
		string input_command;
		getline(cin,input_command);
		std::shared_ptr<CCommand> this_cmd = interpreter.interpret(input_command);
		this_cmd->execute();
		lastCmdName = this_cmd->name;
	}
}

CMainframe::CMainframe(void)
{
	CImage* tmp_img = new CImage();
	src_img = make_shared<CImage>(*tmp_img);
	tmp_img = new CImage();
	dst_img = make_shared<CImage>(*tmp_img);
	resources.clear();
}
