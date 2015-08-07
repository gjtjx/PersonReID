#include "Command.h"
using namespace std;

CCommand::CCommand(string init_name , int init_status):name(init_name),status(-1){}

CCommand::~CCommand(void){}

void CCommand::setStatus(int i)
{
	status = i;
}

void CCommand::execute(void){}

string CCommand::getName(void)
{
	return name;
}

int CCommand::getStatus(void)
{
	return status;
}

void CCommand::displayError(void){}

void CCommand::displayHelp(void){}