/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:36:41 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/29 22:56:29 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap("FTdefault")
{
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	std::cout << "A new FTdefault FragTrap was born" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	std::cout << "A new " << newName << " FragTrap was born" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src.getName())
{
	std::cout << "A new FragTrap was born as copy of " << src.getName() \
	<< std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << this->getName() << " End his life." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap&	FragTrap::operator=(FragTrap const &rhs)
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

std::ostream&	operator<<(std::ostream &o, FragTrap const &i)
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
void FragTrap::attack(const std::string &target)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " doesn't have hit points"
		<< " so it can't attack.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " doesn't have energy points"
		<< " so it can't attack.\n" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!\n"
		<< std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	return;
}

void FragTrap::highFivesGuy(void)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " cannot give high five cause it"
		<< " doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " cannot give high five cause it"
		<< " doesn't have energy points.\n" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->getName() << " says: Give me high five!\n"
		<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */