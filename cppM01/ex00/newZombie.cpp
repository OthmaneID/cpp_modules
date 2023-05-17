#include "Zombie.hpp"


Zombie* Zombie::newZombie( std::string name )
{
	// but here the zombies are gonna be in the heap memory
	Zombie *zombie = new Zombie();

	zombie->name = name;
	return (zombie);
}