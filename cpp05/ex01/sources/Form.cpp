/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:11:50 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/04 18:19:28 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute)
:_name(name), _isSigned(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
	{
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
}

Form::Form(const Form & src)
:_name(src._name), _isSigned(src._isSigned)
{
	if (src._gradeToSign < 1 || src._gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (src._gradeToSign > 150 || src._gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else
	{
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToExecute = src._gradeToExecute;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(){}

/*
** --------------------------------- ASSIGN ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_isSigned = rhs.isSigned();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Form::beSigned(Bureaucrat const &candidate)
{
	if (!this->_isSigned)
	{
		if (candidate.getGrade() <= this->_gradeToSign)
			this->_isSigned = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		throw Form::AlreadySignedException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string	&Form::getName() const
{
	return(this->_name);
}

const bool			&Form::isSigned() const
{
	return(this->_isSigned);
}

const unsigned int	&Form::getGradeToSign() const
{
	return(this->_gradeToSign);
}

const unsigned int	&Form::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

/*
** --------------------------------- EXCEPTIONS ---------------------------------
*/
const char* Form::GradeTooLowException::what() const throw() 
{
	return ("Grade is too low.");
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return ("Grade is too high.");
}

const char* Form::AlreadySignedException::what() const throw() 
{
	return ("Form is already signed");
}

/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "The form: " << i.getName() << ", with grade to sign:\n"
	<< i.getGradeToSign() << " and grade to execute:\n"
	<< i.getGradeToExecute() << std::endl;
	if (i.isSigned())
		o << "is signed." << std::endl;
	else
		o << "is not signed." << std::endl;
	return o;
}


/* ************************************************************************** */