#include "DiamondTrap.hpp"

int main()
{
	ClapTrap Alpha("Alpha");
	ScavTrap Beta("Beta");
	FragTrap Delta("Delta");
	DiamondTrap Epsilon("Epsilon");

	Epsilon.printInfo();
	Epsilon.attack("Delta");
	Delta.printInfo();
	Epsilon.printInfo();
	Delta.beRepaired(8);
	Delta.printInfo();
	Delta.takeDamage(1);
	Delta.attack("Epsilon");
	Epsilon.printInfo();
	Delta.setAttackDamage(2);
	Delta.attack("Epsilon");
	Delta.printInfo();
	Epsilon.attack("Epsilon");
	Epsilon.attack("Alpha");
	Alpha.beRepaired(32);
	Alpha.attack("Epsilon");
	Epsilon.setEnergyPoints(77);
	Epsilon.attack("Delta");
	Epsilon.printInfo();
	Delta.printInfo();
	Epsilon.attack("Delta");
	Beta.guardGate();
	Delta.highFivesGuys();
	Epsilon.whoAmI();
	return 0;
}