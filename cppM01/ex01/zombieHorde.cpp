#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	// but here the zombies are gonna be in the heap memory
	Zombie *zombie = new Zombie();

	zombie->name = name;
	return (zombie);
}

// Zombie* zombieHorde( int N, std::string name )
// {
// 	Zombie *zombie = new Zombie[N];

// 	for(int i = 0; i < N; i++)
// 	{
// 		zombie[i] = Zombie::newZombie(name);
// 	}
// }