/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:19 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/04 19:30:08 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("DiamondDefault_clap_name"), \
FragTrap("DiamondDefault_clap_name"), ScavTrap("DiamondDefault_clap_name")
{
	DiamondTrap::setName("DiamondDefault");
	FragTrap::setHitPoint(100);
	ScavTrap::setEnergyPoint(50);
	FragTrap::setAttackDamage(30);
	std::cout << "A new DiamondDefault DiamondTrap was born" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &newName) : ClapTrap(newName + "_clap_name"), \
FragTrap(newName + "_clap_name"), ScavTrap(newName + "_clap_name")
{
	DiamondTrap::setName(newName);
	FragTrap::setHitPoint(100);
	ScavTrap::setEnergyPoint(50);
	FragTrap::setAttackDamage(30);
	std::cout << "A new " << newName << " DiamondTrap was born" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	*this = src;
	std::cout << "A new DiamondTrap was born as copy of " << src.getName() \
	<< std::endl;
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
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
		this->ClapTrap::setName(rhs.ClapTrap::getName());
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
	ScavTrap::setAttackDamage(20);
	ScavTrap::attack(target);
	FragTrap::setAttackDamage(30);
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
std::string		DiamondTrap::getName(void) const
{
	return(this->_name);
}

void			DiamondTrap::setName(std::string newName)
{
	this->_name = newName;
	return;
}
/* ************************************************************************** */