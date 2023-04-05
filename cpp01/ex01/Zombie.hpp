#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
	private:
		std::string name;
};

Zombie *createZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif