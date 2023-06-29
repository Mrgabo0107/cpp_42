/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:35:30 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/26 21:06:11 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

ClapTrap::ClapTrap()
: _name("CTdefault"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "New ClapTrap created with name: CTdefault" << std::endl; 
}

ClapTrap::ClapTrap(std::string newName)
: _name(newName), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "New ClapTrap created with name: " << newName << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "A copy of " << src.getName() << " was made" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << this->getName() << " has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs)
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


std::ostream&	operator<<(std::ostream &o, ClapTrap const &i)
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

void ClapTrap::attack(const std::string &target)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " wanted to attack but couldn't"
		<< " cause it doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " wanted to attack but couldn't"
		<< " cause it doesn't have energy points.\n" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target
		<< ", causing " << this->getAttackDamage() << " points of damage!\n"
		<< std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " cannot take damage"
		<< " cause it doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " cannot take damage"
		<< " cause it doesn't have energy points.\n" << std::endl;
	}
	else
	{
		unsigned int totalAmount;

		if (amount > this->getHitPoint())
		{
			std::cout << "The amount of damage is greater than the hit "
			<< "points, so:\n" << std::endl;
			totalAmount = this->getHitPoint();
		}
		else
			totalAmount = amount;
		std::cout << this->getName() << " takes " << totalAmount
		<< " points of damage.\n" << std::endl;
		this->setHitPoint(this->getHitPoint() - totalAmount);
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoint() == 0)
	{
		std::cout << this->getName() << " cannot be repaired"
		<< " cause it doesn't have hit points.\n" << std::endl;
	}
	else if (this->getEnergyPoint() == 0)
	{
		std::cout << this->getName() << " cannot be repaired"
		<< " cause it doesn't have energy points.\n" << std::endl;
	}
	else
	{
		long unsigned int totalAmount = (long unsigned int)this->getHitPoint() \
		+ (long unsigned int)amount;

		if (totalAmount >= UINT_MAX)
		{
			std::cout << "the amount of repair points reaches the "
			<< "maximum of possible hit points, so:" << std::endl;
			std::cout << this->getName() << " has been repaired "
			<< "reaching " << UINT_MAX << " hit points.\n" << std::endl;
			this->setHitPoint(UINT_MAX);
			this->setEnergyPoint(this->getEnergyPoint() - 1);
		}
		else
		{
			std::cout << this->getName() << " has been repaired "
			<< "reaching " << totalAmount << " hit points\n" << std::endl;
			this->setHitPoint((unsigned int)totalAmount);
			this->setEnergyPoint(this->getEnergyPoint() - 1);
		}
	}
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

//Getters
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoint(void) const
{
	return (this->_hitPoint);
}

unsigned int	ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoint);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

//Setters
void	ClapTrap::setName(std::string newName)
{
	this->_name = newName;
	return;
}

void	ClapTrap::setHitPoint(unsigned int i)
{
	this->_hitPoint = i;
	return;
}

void	ClapTrap::setEnergyPoint(unsigned int i)
{
	this->_energyPoint = i;
	return;
}

void	ClapTrap::setAttackDamage(unsigned int i)
{
	this->_attackDamage = i;
	return;
}
/* ************************************************************************** */