#include "Command.h"
#include "Data.h"

class CCmdDelImg : public CCommand
{
public:
	CCmdDelImg(int init_status, int serial, std::vector< std::shared_ptr<CImage> >*resource);
	CCmdDelImg(std::string sargs, std::vector<std::shared_ptr<CImage> >* resource);
	~CCmdDelImg(void);
	void execute(void) override;
	void displayError(int err_num = 0) override;
	void displayHelp(void) override;
private:
	std::vector< std::shared_ptr<CImage> >* rcs;
	int serial;
};