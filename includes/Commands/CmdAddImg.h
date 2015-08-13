#ifndef CMDADDIMG_H
#define CMDADDIMG_H

#include "Command.h"
#include "Data.h"
#include <unordered_map>

class CCmdAddImg : public CCommand
{
	public:
	CCmdAddImg(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	CCmdAddImg(int status, std::string id, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	void execute(void) override;
	~CCmdAddImg(void);
	void displayError(int err_num=0) override;
	void displayHelp(void) override;
private:
	std::unordered_map<std::string,std::shared_ptr<CImage> > *rcs;
	std::string dst_id;
};


#endif