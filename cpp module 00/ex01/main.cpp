#include "PhoneBook.hpp"
#define ADD 1
#define SEARCH 2
#define EXIT 3

void	get_input(void)
{
	std::string input;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "ENTER YOUR CHOICE: \n1_ ADD\n2_ SEARCH\n3_ EXIT " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		else if (!input.compare("ADD"))
			phonebook.add_contact();
		else if (!input.compare("SEARCH"))
			phonebook.Search();
		else if (!input.compare("EXIT"))
			break ;
		else
			std::cout << "PLEASE ENTER A VALID CHOICE :" << std::endl;
	}
}

int	main(void)
{
	get_input();
	return (0);
}