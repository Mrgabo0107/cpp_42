#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Form::Form(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
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
	if (src.gradeToSign < 1 || src.gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (src.gradeToSign > 150 || src.gradeToExecute > 150)
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
		this->_gradeToSign = rhs.gradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void Form::beSigned(Bureaucrat const &candidate) const;
{
	if (!this->_signed)
	{
		if (candidate.getGrade() <= this->_gradeSign)
			this->_signed = true;
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
	return(this->gradeToSign);
}

const unsigned int	&Form::getGradeToExecute() const
{
	return(this->gradeToExecute);
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