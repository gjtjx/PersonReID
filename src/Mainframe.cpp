#include "Mainframe.h"
using namespace std;

void CMainframe::Run(void)
{
	string lastCmdName = "";
	CInterpreter interpreter(this);
	while("Exit" != lastCmdName)
	{
		string input_command;
		getline(cin,input_command);
		std::shared_ptr<CCommand> this_cmd = interpreter.interpret(input_command);
		this_cmd->execute();
		lastCmdName = this_cmd->name;
	}
}