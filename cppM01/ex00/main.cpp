#include "Zombie.hpp"

int main()
{
	Zombie *zombie = Zombie::newZombie("foo");

	zombie->announce();
	delete zombie;
}