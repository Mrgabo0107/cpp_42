#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
AForm::AForm(const std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
:_name(name), _isSigned(false)
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

AForm::AForm(const AForm & src)
:_name(src._name), _isSigned(src._isSigned)
{
	if (src.gradeToSign < 1 || src.gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (src.gradeToSign > 150 || src.gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
	{
		this->_gradeToSign = src._gradeToSign;
		this->_gradeToExecute = src._gradeToExecute;
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
		this->_isSigned = rhs.isSigned();
		this->_gradeToSign = rhs.gradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void AForm::beSigned(const Bureaucrat &candidate);
{
	if (!this->_signed)
	{
		if (candidate.getGrade() <= this->_gradeSign)
			this->_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::AlreadySignedException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string	&AForm::getName() const
{
	return(this->_name);
}

const bool			&AForm::isSigned() const
{
	return(this->_isSigned);
}

const unsigned int	&AForm::getGradeToSign() const
{
	return(this->gradeToSign);
}

const unsigned int	&AForm::getGradeToExecute() const
{
	return(this->gradeToExecute);
}

/*
** --------------------------------- EXCEPTIONS ---------------------------------
*/
const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("Grade is to low.");
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return ("Grade is to high.");
}

const char* AForm::AlreadySignedException::what() const throw() 
{
	return ("AForm is already signed");
}

/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "The AForm: " << i.getName() << ", with grade to sign:\n"
	<< i.getGradeToSign() << " and grade to execute:\n"
	<< i.gradeToExecute() << std::endl;
	if (i.isSigned)
		o << "is signed." << std::endl;
	else
		o << "is not signed." << std::endl;
	return o;
}


/* ************************************************************************** */