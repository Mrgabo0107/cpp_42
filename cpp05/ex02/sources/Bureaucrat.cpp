/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:13:09 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/02 18:34:44 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade)
{
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	if (src.getGrade() <= 0)
		throw Bureaucrat::GradeTooHighException();
	else if (src.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_name = src.getName();
	this->_grade = src.getGrade();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Bureaucrat::~Bureaucrat(){}

/*
** --------------------------------- ASSIGN ---------------------------------
*/
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	Bureaucrat::upGrade() const
{
	if (this->_grade - 1 <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::downGrade() const
{
	if (this->_grade + 1 >= 151)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

void	Bureaucrat::signAForm(AForm& AForm) const
{
	try
	{
		AForm.beSigned(*this);
		std::cout << *this << " signed " << AForm << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << " cannot sign " << AForm << " because " << e.what() << std::endl;
	}
	
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() \
				  << " because " << e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

const unsigned int	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/*
** --------------------------------- EXCEPTIONS ---------------------------------
*/
const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Grade is to low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("Grade is to high.");
}

/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade" << i.getGrade() << std::endl;
	return o;
}


/* ************************************************************************** */