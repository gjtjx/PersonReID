#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <memory>
class CCommand
{
public:
	static std::shared_ptr<CCommand> create(std::string);
	CCommand(void);
	const std::string name;
	virtual void execute(void);
	virtual ~CCommand(void);
	int status = -1;
	virtual void displayHelp(void);
	virtual void displayError(void);
	
private:
};

class CData
{
public:
	virtual ~CData(void);
};

#endif
