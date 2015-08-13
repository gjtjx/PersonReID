#ifndef CMDHELP_H
#define CMDHELP_H

#include "Command.h"

class CCmdHelp : public CCommand
{
public:
	CCmdHelp(int type);
	CCmdHelp(std::string sargs);
	~CCmdHelp(void);
	void execute(void) override;
	void displayHelp(void) override;
	void displayError(int err_num=0) override;
	void displayCmdhelp(int cmd_serial);
};


#endif