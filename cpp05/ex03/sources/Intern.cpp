/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:01:07 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/07 22:15:21 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Intern::Intern()
{}

Intern::Intern(const Intern &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Intern::~Intern()
{}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/
Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhc; 
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AForm	*Intern::makeForm(std::string form, std::string target)
{
	int i;
	std::string	forms[3] = {"Shrubbery" , "Presidential", "Robotomy"};

	for (i = 0; i < 3; i++)
	{
		if (form == forms[i])
			break ;
	}
	switch (i)
	{
	case 0:
		std::cout << "Intern creates shrubbery creation form" << std::endl;
		return (new ShrubberyCreationForm(target));
		break;
	case 1:
		std::cout << "Intern creates presidential pardon form" << std::endl;
		return (new PresidentialPardonForm(target));
		break;
	case 2:
		std::cout << "Intern creates robotomy request form" << std::endl;
		return (new RobotomyRequestForm(target));
		break;
	default:
		std::cout << "Intern cannot find form." << std::endl;
		return (nullptr);
		break;
	}
}

/* ************************************************************************** */