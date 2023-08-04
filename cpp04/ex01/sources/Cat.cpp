/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:22:59 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 08:22:02 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	this->_brain = new Brain();
	*this->_brain = *src._brain;
	std::cout << "Cat created as a copy" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat object destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat&	Cat::operator=(const Cat &rhs)
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

void Cat::makeSound() const
{
	std::cout << "Cat: (cat purring)" << std::endl;
}

void	Cat::printBrain() const
{
	for (int i = 0; i < 99; i++)
		std::cout << this->_brain->getIdeas()[i] << ", ";
	std::cout << this->_brain->getIdeas()[99] << std::endl;
}

void	Cat::setBrain(std::string idea)
{
	this->_brain->setIdeas(idea);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */