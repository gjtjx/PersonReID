#ifndef CMDNOTVALID_H
#define CMDNOTVALID_H
#include "Common.h"
#include <iostream>
#include <string>

class CCmdNotValid : public CCommand
{
public:
	const std::string name;
	CCmdNotValid(void);
	void execute(void);
	~CCmdNotValid(void);
	std::shared_ptr<CCommand> CCmdNotValid::create(std::string s);
private:

};

#endif
