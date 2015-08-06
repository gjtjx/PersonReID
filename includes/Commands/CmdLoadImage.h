#ifndef CMDLOADIMAGE_H
#define CMDLOADIMAGE_H
#include "Image.h"
#include "Common.h"
#include <string>

class CCmdLoadImage : public CCommand
{
public:
	const std::string name;
	CCmdLoadImage(std::string = "" , CImage* = nullptr, bool = 1);
	void execute(void);
	~CCmdLoadImage(void);
	void displayHelp(void);
	
private:
	std::string src_path;
	CImage* dstImage;
};

#endif
