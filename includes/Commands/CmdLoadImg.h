#ifndef CMDLOADIMG_H
#define CMDLOADIMG_H
#include "Data.h"
#include "Command.h"
#include <string>

class CCmdLoadImg : public CCommand
{
public:
	CCmdLoadImg(std::string sargs, std::shared_ptr<CImage>);
	CCmdLoadImg(std::string src_path, int status, std::shared_ptr<CImage>);
	void execute(void) override;
	~CCmdLoadImg(void);
	void displayHelp(void) override;
	void displayError(void) override;
private:
	std::string src_path;
	std::shared_ptr<CImage> dstImage;
};

#endif
