#include "Command.h"

CCommand::CCommand(void)
{
	name = "untitled";
	status = -1;
}

CCommand::~CCommand(void){}

void CCommand::execute(void){}

void CCommand::displayError(void){}

void CCommand::displayHelp(void){}