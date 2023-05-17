#include <iostream>
#include <string>
#define FIRST 0
#define LAST 1
#define NICK 2
#define SECRET 3
#define INDEX 4
#define PHONE 5

class Contacts
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;
		std::string	Phone_Number;
	public:
		void		set_value(std::string val, int type);
		std::string	get_value(int type);
		void		Display_infos();
		void		Display_truncated();
};