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
	void execute(void);
	~CCmdLoadImg(void);
private:
	void displayHelp(void);
	void displayError(void);
	std::string src_path;
	std::shared_ptr<CImage> dstImage;
};

#endif
