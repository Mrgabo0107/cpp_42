/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:38 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 02:02:46 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Animal::Animal(const std::string &type)
{
	this->_type = type;
	std::cout << "Animal Created" << std::endl;
}


Animal::Animal()
{
	this->_type = "GenericAnimal";
	std::cout << "Animal Created" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal created as a copy" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal&		Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<(std::ostream &o, const Animal &i)
{
	o << "Animal type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void Animal::makeSound() const
{
	std::cout << "Animal: random sound" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType() const
{
	return (this->_type);
}
/* ************************************************************************** */