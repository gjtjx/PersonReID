#ifndef CMDHELP_H
#define CMDHELP_H

#include "Command.h"
#include <string>
#include <iostream>

class CCmdHelp : public CCommand
{
public:
	CCmdHelp(int type);
	void execute(void);
	~CCmdHelp(void);
private:

};


#endif