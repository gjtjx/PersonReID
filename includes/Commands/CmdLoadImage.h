#ifndef CMDLOADIMAGE_H
#define CMDLOADIMAGE_H
#include "Image.h"
#include "Common.h"
#include "Command.h"
#include <string>

class CCmdLoadImage : public CCommand
{
public:
	static std::shared_ptr<CCmdLoadImage> create(std::string, std::shared_ptr<CImage>);
	CCmdLoadImage(std::string, std::shared_ptr<CImage> , int);
	void execute(void);
	~CCmdLoadImage(void);
private:
	void displayHelp(void);
	void displayError(void);
	std::string src_path;
	std::shared_ptr<CImage> dstImage;
};

#endif
