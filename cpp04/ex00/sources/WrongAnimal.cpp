/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:38 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 02:05:25 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
WrongAnimal::WrongAnimal(const std::string &type)
{
	this->_type = type;
	std::cout << "WrongAnimal Created" << std::endl;
}


WrongAnimal::WrongAnimal()
{
	this->_type = "GenericWrongAnimal";
	std::cout << "WrongAnimal Created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "WrongAnimal created as a copy" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal&		WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<(std::ostream &o, const WrongAnimal &i)
{
	o << "WrongAnimal type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal: random sound" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
/* ************************************************************************** */