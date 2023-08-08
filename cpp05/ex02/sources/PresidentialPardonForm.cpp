#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm(src)
{}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
PresidentialPardonForm::~PresidentialPardonForm()
{}

/*
** --------------------------------- ASSIGN ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		this->AForm::setName(rhs.AForm::getName());
		this->AForm::setTarget(rhs.AForm::getTarget());
		this->AForm::setSigned(rhs.AForm::isSigned());
		this->AForm::setGradeToSign(rhs.AForm::getGradeToSign());
		this->AForm::setGradeToExecute(rhs.AForm::getGradeToExecute());
	}
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

void		PresidentialPardonForm::action() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/* ************************************************************************** */
