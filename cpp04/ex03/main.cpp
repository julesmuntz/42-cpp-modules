#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << std::endl;
	IMateriaSource *src = new MateriaSource();

	std::cout << std::endl;
	src->learnMateria(new Ice());

	std::cout << std::endl;
	src->learnMateria(new Cure());

	std::cout << std::endl;

	ICharacter *me = new Character("me");

	AMateria *tmp;

	std::cout << std::endl;
	tmp = src->createMateria("fire");
	me->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("explosion");
	me->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("boost");
	me->equip(tmp);

	std::cout << std::endl;
	ICharacter *bob = new Character("bob");
	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-1, *bob);

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	bob->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	bob->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("ice");
	bob->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("uppercut");
	bob->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("thunder");
	bob->equip(tmp);

	std::cout << std::endl;
	tmp = src->createMateria("cure");
	bob->equip(tmp);

	bob->use(4, *me);
	bob->use(2, *me);
	bob->use(3, *me);
	bob->use(3, *me);
	bob->use(1, *me);
	bob->use(100, *me);
	bob->use(-32, *me);

	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	std::cout << std::endl;

	return 0;
}
