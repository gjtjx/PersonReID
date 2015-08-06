#ifndef CMDNOTVALID_H
#define CMDNOTVALID_H
#include "Common.h"
#include "Command.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class CCmdNotValid : public CCommand
{
public:
	static std::shared_ptr<CCmdNotValid> create(std::string s);
	CCmdNotValid(int);
	void execute(void);
	~CCmdNotValid(void);
private:
	void displayHelp(void);
	void displayError(void);
};

#endif
