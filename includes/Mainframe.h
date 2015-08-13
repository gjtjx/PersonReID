#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <iostream>
#include "Interpreter.h"
#include <vector>
#include "Data.h"
#include <memory>
#include <unordered_map>

class CMainframe
{
public:
	void Run();
	CMainframe(void);
	std::unordered_map<std::string,std::shared_ptr<CImage> > resources;
};

#endif