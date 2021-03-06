#ifndef CMDEXIT_H
#define CMDEXIT_H

#include "Command.h"

class CCmdExit : public CCommand
{
public:
	CCmdExit(int status, std::string msg = "exit");
	CCmdExit(std::string args);
	~CCmdExit(void);
	void execute(void) override;
	void displayHelp(void) override;
	void displayError(void) override;
private:
	std::string msg;
};

#endif