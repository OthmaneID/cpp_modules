#include "Contacts.hpp"


void	Contacts::set_value(std::string val, int type)
{
	switch (type)
	{
		case FIRST:
			this->first_name = val;
			break;
		case LAST:
			this->last_name = val;
			break;
		case NICK:
			this->nick_name = val;
			break;
		case SECRET:
			this->darkest_secret = val;
		case PHONE:
			this->Phone_Number = val;
			break;
	}
}

std::string	Contacts::get_value(int type)
{
	switch (type)
	{
		case FIRST:
			return this->first_name;
			break;
		case LAST:
			return this->last_name;
			break;
		case NICK:
			return this->nick_name;
			break;
		case SECRET:
			return this->darkest_secret;
		case PHONE:
			return this->Phone_Number;
			break;
	}
	return (NULL);
}

void	Contacts::Display_infos()
{
	std::cout << "First Name : " << get_value(FIRST) << std::endl;
	std::cout << "Last  Name : " << get_value(LAST) << std::endl;
	std::cout << "Nick  Name : " << get_value(NICK) << std::endl;
	std::cout << "Darkest Secret : " << get_value(SECRET) << std::endl;
	std::cout << "Phone Number : " << get_value(PHONE) << std::endl;
}
