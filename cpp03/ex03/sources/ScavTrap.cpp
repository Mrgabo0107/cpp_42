/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:36:41 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/26 21:05:01 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap("STdefault")
{
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	std::cout << "A new STdefault ScavTrap was born" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	std::cout << "A new " << newName << " ScavTrap was born" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src.getName())
{
	std::cout << "A new ScavTrap was born as copy of " << src.getName() \
	<< std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " died..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs)
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

std::ostream&	operator<<(std::ostream &o, ScavTrap const &i)
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
void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " cannot attack cause it"
		<< " doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " cannot attack cause it"
		<< " doesn't have energy points.\n" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!\n"
		<< std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	return;
}

void ScavTrap::guardGate(void)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " cannot guard the gate cause it"
		<< " doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " cannot guard the gate cause it"
		<< " doesn't have energy points.\n" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->getName() << " now is in gate keeper mode.\n"
		<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */