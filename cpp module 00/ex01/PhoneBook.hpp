#include <iostream>
#include <string>
#include "Contacts.hpp"

class PhoneBook
{
	private:
		Contacts	contacts[8];
		int			index;
	public:
		PhoneBook(void);
		int			add_contact();
		int			get_index(void);
		void		Search();
		int 		set_Contacts(std::string val, int TYPE);
		Contacts	get_contacts(int index);
};
