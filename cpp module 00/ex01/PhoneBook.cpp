#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :
	index(0){}
int	PhoneBook::set_Contacts(std::string val, int TYPE)
{
	if (std::cin.eof())
	{
		std::cerr << "^D"<<std::endl;
		exit(0);
	}
	if (val.empty())
		return (0);
	contacts[index % 8].set_value(val, TYPE);
	index++;
	return (1);
}
// fix the code above
Contacts PhoneBook::get_contacts(int index)
{
	return (contacts[index]);
}

//helper Functions
int	is_phone(std::string phone)
{
	if (std::cin.eof())
	{
		std::cerr << "^D"<<std::endl;
		exit(0);
	}
	if (phone.empty())
		return (0);
	if (phone.length() != 10)
	{
		std::cerr << "Phone length should be 10 character length : "<<std::endl;
		return (0);
	}
	for (int i = 0; i < phone.length(); i++)
		if (phone[i] < '0' || phone[i] > '9')
		{
			std::cerr << "Invalid Phone Number : "<<std::endl;
			return (0);
		}
	return (1);
}

int fill(int n, char c)
{
	for(int	i = 0; i < n ; i++)
		std::cout << c;
	return (0);
}

void	Display_Truncated(std::string to_truncate)
{
	std::cout <<  ((to_truncate.length() > 10) ? (to_truncate.substr(0, 7)) : (to_truncate));
	((to_truncate.length() > 10) ? fill(3, '.') : fill(10 - to_truncate.length(), ' '));
	std::cout << "|";
}
//helper Functions--------------_END

int	PhoneBook::get_index(void)
{
	return (index);
}

int	PhoneBook::add_contact()
{
	std::string input;

	first:std::cin.clear();
	std::cout << "ENTER FIRST NAME: " << std::endl;
	std::getline(std::cin, input);
	if (!set_Contacts(input, FIRST))
		goto first;
	last:std::cin.clear();
	std::cout << "ENTER LAST NAME: " << std::endl;
	std::getline(std::cin, input);
	if (!set_Contacts(input, LAST))
		goto last;
	nick:std::cin.clear();
	std::cout << "ENTER NICK NAME: " << std::endl;
	std::getline(std::cin, input);
	if (!set_Contacts(input, NICK))
		goto nick;
	secret:std::cin.clear();
	std::cout << "ENTER A SECRET: " << std::endl;
	std::getline(std::cin, input);
	if (!set_Contacts(input, SECRET))
		goto secret;
	Phone: std::cin.clear();
	std::cout << "ENTER A Phone Number: " << std::endl;
	std::getline(std::cin, input);
	if (!is_phone(input) || !set_Contacts(input, PHONE))
		goto Phone;
	return (1);
}

void	PhoneBook::Search()
{
	int index = 0;
	Contacts contact;
	std::string to_truncate;
	std::string	chose_index;

	std::cout << "|   INDEX  |first name|last name |nick name |" << std::endl;
	while (index < get_index())
	{
		contact = get_contacts(index);
		to_truncate = contact.get_value(FIRST);
		std::cout << "|    " << index++ % 8 << "     |";
		Display_Truncated(to_truncate);
		to_truncate = contact.get_value(LAST);
		Display_Truncated(to_truncate);
		to_truncate = contact.get_value(NICK);
		Display_Truncated(to_truncate);
		std::cout <<std::endl;
	}
	std::cout << "Put index for more details or (^D / ENTER) for previous choices :" << std::endl;
	std::getline(std::cin, chose_index);
	std::cin.clear();
	if (chose_index.empty())
		return ;
	index = std::stoi(chose_index);
	if (index > get_index() || index < 0 || index > 7)
	{
		std::cerr << "contact not availble" << std::endl;
		return ;
	}
	contact = get_contacts(index);
	contact.Display_infos();
}