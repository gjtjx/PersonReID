#ifndef CMDLOADIMG_H
#define CMDLOADIMG_H
#include "Data.h"
#include "Command.h"
#include <string>
#include <unordered_map>

class CCmdLoadImg : public CCommand
{
public:
	CCmdLoadImg(std::string sargs, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	CCmdLoadImg(std::string src_path, std::string id, int init_status, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	void execute(void) override;
	~CCmdLoadImg(void);
	void displayHelp(void) override;
	void displayError(int err_num=0) override;
private:
	std::string src_path;
	std::unordered_map<std::string,std::shared_ptr<CImage> > *rcs;
	std::string dst_id;
};

#endif
