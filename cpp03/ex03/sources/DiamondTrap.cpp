#include "../includes/DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("DiamondDefault_clap_name"), \
FragTrap("DiamondDefault"), ScavTrap("DiamondDefault")
{
	this->setName("DiamondDefault");
	this->setHitPoint(FragTrap::getHitPoint());
	this->setEnergyPoint(ScavTrap::getEnergyPoint());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "A new DiamondDefault DiamondTrap was born" << std::endl;
}

DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName + "_clap_name"), \
FragTrap(newName), ScavTrap(newName)
{
	this->setName(newName);
	this->setHitPoint(FragTrap::getHitPoint());
	this->setEnergyPoint(ScavTrap::getEnergyPoint());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "A new " << newName << " DiamondTrap was born" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
: ClapTrap(src.getName() + "_clap_name"), FragTrap(src.getName()), \
ScavTrap(src.getName())
{
	std::cout << "A new DiamondTrap was born as copy of " << src.getName() \
	<< std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << this->getName() << " is a destroyed diamond" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoint(rhs.getHitPoint());
		this->setEnergyPoint(rhs.getEnergyPoint());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}

std::ostream&	operator<<(std::ostream &o, DiamondTrap const &i)
{
	o << "Name = " << i.getName() << '\n'
	<< "Hit points = " << i.getHitPoint() << '\n'
	<< "Energy points = " << i.getEnergyPoint() << '\n'
	<< "Attack damage = " << i.getAttackDamage() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
	return;
}

void DiamondTrap::whoAmI(void)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " cannot wonder about itself cause"
		<< " doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " cannot wonder about itself cause"
		<< " doesn't have energy points.\n" << std::endl;
	}
	else
		std::cout << "I am " << this->getName() << " as a Diamond but also "
		<< ClapTrap::getName() << " as a ClapTrap." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */