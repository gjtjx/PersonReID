#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>
class CCommand
{
public:
	CCommand(void);
	int status;
	std::string name;
	virtual void execute(void);
	virtual ~CCommand(void);
private:
	virtual void displayHelp(void);
	virtual void displayError(void);
};

#endif