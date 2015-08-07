#ifndef CMDHELP_H
#define CMDHELP_H

#include "Command.h"
#include <string>
#include <iostream>

class CCmdHelp : public CCommand
{
public:
	CCmdHelp(int type);
	CCmdHelp(std::string sargs);
	~CCmdHelp(void);
	void execute(void) override;
	void displayHelp(void) override;
	void displayError(void) override;
};


#endif