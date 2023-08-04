/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:46 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 08:33:47 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	this->_brain = new Brain();
	*this->_brain = *src._brain;
	std::cout << "Dog created as a copy" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog object destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog&	Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		*this->_brain = *rhs._brain;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	std::cout << "Dog: woof woof" << std::endl;
}

void	Dog::printBrain() const
{
	for (int i = 0; i < 99; i++)
		std::cout << this->_brain->getIdeas()[i] << ", ";
	std::cout << this->_brain->getIdeas()[99] << std::endl;
}

void	Dog::setBrain(std::string idea)
{
	this->_brain->setIdeas(idea);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */