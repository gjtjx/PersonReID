#ifndef CMDNOTVALID_H
#define CMDNOTVALID_H
#include "Data.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class CCmdNotValid : public CCommand
{
public:
	CCmdNotValid(int status);
	CCmdNotValid(std::string args);
	~CCmdNotValid(void);
	void execute(void);
private:
	void displayHelp(void);
	void displayError(void);
};

#endif
