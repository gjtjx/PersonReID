#ifndef CMDADDIMG_H
#define CMDADDIMG_H

#include "Command.h"
#include "Data.h"

class CCmdAddImg : public CCommand
{
	public:
	CCmdAddImg(std::string sargs, std::vector< std::shared_ptr<CImage> >*);
	CCmdAddImg(int status, std::vector< std::shared_ptr<CImage> >*);
	void execute(void) override;
	~CCmdAddImg(void);
	void displayError(int err_num=0) override;
	void displayHelp(void) override;
private:
	std::vector< std::shared_ptr<CImage> >*rcs;
};


#endif