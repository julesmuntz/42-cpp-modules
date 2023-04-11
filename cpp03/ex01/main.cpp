#include "ScavTrap.hpp"

int main()
{
	ClapTrap Alpha("Alpha");
	ScavTrap Beta("Beta");
	ClapTrap Gamma("Gamma");
	ScavTrap Delta("Delta");

	Alpha.printInfo();
	Beta.printInfo();
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
	Gamma.printInfo();
	Gamma.setAttackDamage(4);
	Gamma.attack("Beta");
	Delta.printInfo();
	Gamma.printInfo();
	Delta.beRepaired(8);
	Delta.printInfo();
	Delta.takeDamage(1);
	Delta.attack("Gamma");
	Gamma.printInfo();
	Delta.setAttackDamage(2);
	Delta.attack("Gamma");
	Delta.printInfo();
	Gamma.attack("Gamma");
	Gamma.setAttackDamage(18);
	Gamma.setEnergyPoints(77);
	Gamma.attack("Delta");
	Gamma.printInfo();
	Delta.printInfo();
	Gamma.attack("Delta");
	Beta.guardGate();
	return 0;
}