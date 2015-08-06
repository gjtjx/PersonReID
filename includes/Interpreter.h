#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <unordered_map>
#include <string>
#include "Data.h"
#include "Command.h"
#include <memory>
#include "Image.h"
#include "Mainframe.h"
#include "Commands.h"

class CMainframe;
class CInterpreter
{
public:
	CInterpreter(CMainframe*);
	std::shared_ptr<CCommand> interpret(std::string);
private:
	CMainframe* mainframe;
	std::unordered_map <std::string,int> cmd_table;
};

#endif
