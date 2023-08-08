/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:53:42 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/08 23:31:47 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
AForm::AForm(const std::string name, const std::string target, \
const unsigned int gradeToSign, const unsigned int gradeToExecute)
:_name(name), _target(target), _isSigned(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
	{
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
}

AForm::AForm(const AForm &src)
:_name(src.getName()), _target(src.getTarget()), _isSigned(src.isSigned())
{
	if (src._gradeToSign < 1 || src._gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (src._gradeToSign > 150 || src._gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
	{
		this->_gradeToSign = src.getGradeToSign();
		this->_gradeToExecute = src.getGradeToExecute();
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm(){}

/*
** --------------------------------- ASSIGN ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_target = rhs.getTarget();
		this->_isSigned = rhs.isSigned();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void AForm::beSigned(const Bureaucrat &candidate)
{
	if (!this->_isSigned)
	{
		if (candidate.getGrade() <= this->_gradeToSign)
			this->_isSigned = true;
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::AlreadySignedException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw AForm::notSignedException();
	else if (this->_gradeToExecute < executor.getGrade())
		throw AForm::GradeTooLowException();
	else
		this->action();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string	&AForm::getName() const
{
	return(this->_name);
}

const std::string	&AForm::getTarget() const
{
	return(this->_target);
}

const bool			&AForm::isSigned() const
{
	return(this->_isSigned);
}

const unsigned int	&AForm::getGradeToSign() const
{
	return(this->_gradeToSign);
}

const unsigned int	&AForm::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

void AForm::setName(std::string name)
{
	this->_name = name;
}

void AForm::setTarget(std::string target)
{
	this->_target = target;
}

void AForm::setSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

void AForm::setGradeToSign(unsigned int gradeToSign)
{
	this->_gradeToSign = gradeToSign;
}

void AForm::setGradeToExecute(unsigned int gradeToExecute)
{
	this->_gradeToExecute = gradeToExecute;
}

/*
** --------------------------------- EXCEPTIONS ---------------------------------
*/
const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("Grade is too low.");
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return ("Grade is too high.");
}

const char* AForm::AlreadySignedException::what() const throw() 
{
	return ("Form is already signed");
}

const char* AForm::notSignedException::what() const throw() 
{
	return ("Form is not signed");
}

/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "The AForm: " << i.getName() << "\nwith grade to sign: "
	<< i.getGradeToSign() << "\ngrade to execute: "
	<< i.getGradeToExecute() << "\nand target: "
	<< i.getTarget() << std::endl;
	if (i.isSigned())
		o << "is signed." << std::endl;
	else
		o << "is not signed." << std::endl;
	return o;
}


/* ************************************************************************** */