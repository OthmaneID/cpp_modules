#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		~Zombie();
		static Zombie* Zombie::newZombie( std::string name );
		static Zombie* zombieHorde( int N, std::string name );
};