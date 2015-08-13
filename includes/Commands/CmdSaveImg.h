#ifndef CMDSAVEIMG_H
#define CMDSAVEIMG_H
#include "Data.h"
#include "Command.h"
#include <string>
#include <unordered_map>

class CCmdSaveImg : public CCommand
{
public:
	CCmdSaveImg(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	CCmdSaveImg(std::string src_path, std::string id, int init_status, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	void execute(void) override;
	~CCmdSaveImg(void);
	void displayHelp(void) override;
	void displayError(int err_num=0) override;
private:
	std::string src_path;
	std::unordered_map<std::string,std::shared_ptr<CImage> > *rcs;
	std::string dst_id;
};

#endif