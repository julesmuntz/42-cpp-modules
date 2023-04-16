#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 2; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 2; i++)
		this->_materia[i] = other._materia[i];
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		if (other._materia[i])
			this->_materia[i] = other._materia[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 2; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for( int i = 0 ; i < 2 ; i++ )
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout << "Cannot learn more than 2 materias (4 at most)." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 2; i++)
	{
		if (this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	std::cout << "Materia \"" << type << "\" not found." << std::endl;
	return NULL;
}
