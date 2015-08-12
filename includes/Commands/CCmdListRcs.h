#ifndef CMDLISTRCS_H
#define CMDLISTRCS_H
#include "Command.h"
#include "Data.h"

class CCmdListRcs : public CCommand
{
public:
	CCmdListRcs(std::string sargs, std::shared_ptr<CImage>, std::shared_ptr<CImage>,std::vector< std::shared_ptr<CImage> >);
	CCmdListRcs(int status, std::shared_ptr<CImage>, std::shared_ptr<CImage>,std::vector< std::shared_ptr<CImage> > );
	void execute(void) override;
	~CCmdListRcs(void);
	void displayError(void) override;
	void displayHelp(void) override;
private:
	std::shared_ptr<CImage> src_img;
	std::shared_ptr<CImage> dst_img;
	std::vector< std::shared_ptr<CImage> > rcs;
};


#endif