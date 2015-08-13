#include "Mainframe.h"
using namespace std;

void CMainframe::Run(void)
{
	string lastCmdName = "";
	CInterpreter interpreter(this);
	while("exit" != lastCmdName)
	{
		cout<<"PersonReID>>";
		string input_command;
		getline(cin,input_command);
		std::shared_ptr<CCommand> this_cmd = interpreter.interpret(input_command);
		this_cmd->execute();
		lastCmdName = this_cmd->getName();
	}
}

CMainframe::CMainframe(void)
{
	shared_ptr<CImage> src = make_shared<CImage>();
	shared_ptr<CImage> dst = make_shared<CImage>();
	resources.insert(pair<string,shared_ptr<CImage> > ("src",src));
	resources.insert(pair<string,shared_ptr<CImage> > ("dst",dst));
}
