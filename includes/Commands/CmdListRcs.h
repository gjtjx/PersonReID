#ifndef CMDLISTRCS_H
#define CMDLISTRCS_H
#include "Command.h"
#include "Data.h"
#include <unordered_map>

class CCmdListRcs : public CCommand
{
public:
	CCmdListRcs(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	CCmdListRcs(int status, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	void execute(void) override;
	~CCmdListRcs(void);
	void displayError(int err_num = 0) override;
	void displayHelp(void) override;
private:
	std::unordered_map<std::string,std::shared_ptr<CImage> > *rcs;
};


#endif