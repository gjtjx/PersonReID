#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <iostream>
#include "Interpreter.h"
#include <vector>
#include "Common.h"
#include <memory>
#include "Image.h"

class CMainframe
{
public:
	void Run();
private:
	std::vector< std::shared_ptr<CImage> > resources;
	std::shared_ptr<CImage> src_img;
	std::shared_ptr<CImage> dst_img;
};

#endif