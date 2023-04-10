#include "ClapTrap.hpp"

int main()
{
	ClapTrap Alpha("Alpha");
	ClapTrap Beta("Beta");

	Alpha.printInfo();
	Alpha.setAttackDamage(4);
	Alpha.attack("Beta");
	Beta.printInfo();
	Alpha.printInfo();
	Beta.beRepaired(8);
	Beta.printInfo();
	Beta.takeDamage(1);
	Beta.attack("Alpha");
	Alpha.printInfo();
	Beta.setAttackDamage(5);
	Beta.attack("Alpha");
	Beta.printInfo();
	Alpha.attack("Sigma");
	Alpha.setAttackDamage(15);
	Alpha.setEnergyPoints(42);
	Alpha.attack("Beta");
	Alpha.printInfo();
	Beta.printInfo();
	return 0;
}