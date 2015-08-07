#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>
class CCommand
{
public:
	//each command must provide :
	//a help message.
	//at least a error message.
	CCommand(std::string name = "untitled" , int status = -1);
	virtual ~CCommand(void);
	virtual void setStatus(int i);
	//execute the command
	virtual void execute(void) = 0;
	virtual std::string getName(void);
	virtual int getStatus(void);
	virtual void displayHelp(void);
	virtual void displayError(void);
private:
	//the name of the command.should be set at initiation
	std::string name;

	//specify the status of the command
	//status -1 is reserved for error status.
	//status 0 is reserved for displaying help.
	//status 1 is usually the normal state.
	int status;
};

#endif