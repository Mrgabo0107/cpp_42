#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
AForm::AForm(const std::string name, const std::string target, \
const unsigned int gradeToSign, const unsigned int gradeToExecute);
:_name(name), _target(target) _isSigned(false)
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
:_name(src._name), _target(src._target), _isSigned(src._isSigned)
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
		this->_target = rhs.getTarget();
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

void AForm::execute(Bureaucrat const &executor) const;
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
	return(this->gradeToSign);
}

const unsigned int	&AForm::getGradeToExecute() const
{
	return(this->gradeToExecute);
}

void setName(std::string name) const
{
	this->_name = name;
}

void setTarget(std::string target) const
{
	this->_target = target;
}

void setSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

void setGradeToSign(unsigned int gradeToSign) const
{
	this->_gradeToSign = gradeToSign;
}

void setGradeToExecute(unsigned int gradeToExecute) const
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
	o << "The AForm: " << i.getName() << ", with grade to sign:\n"
	<< i.getGradeToSign() << ", grade to execute:\n"
	<< i.getGradeToExecute() << " and target:\n";
	<< i.getTarget() << std::endl;
	if (i.isSigned())
		o << "is signed." << std::endl;
	else
		o << "is not signed." << std::endl;
	return o;
}


/* ************************************************************************** */