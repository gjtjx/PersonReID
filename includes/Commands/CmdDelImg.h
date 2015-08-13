#include "Command.h"
#include "Data.h"
#include <string>
#include <unordered_map>

class CCmdDelImg : public CCommand
{
public:
	CCmdDelImg(int init_status, std::string id, std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	CCmdDelImg(std::string sargs,std::unordered_map<std::string,std::shared_ptr<CImage> > *resources);
	~CCmdDelImg(void);
	void execute(void) override;
	void displayError(int err_num = 0) override;
	void displayHelp(void) override;
private:
	std::unordered_map<std::string,std::shared_ptr<CImage> > *rcs;
	std::string dst_id;
};