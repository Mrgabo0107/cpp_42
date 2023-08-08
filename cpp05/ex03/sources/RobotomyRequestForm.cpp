#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm(src)
{}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{}

/*
** --------------------------------- ASSIGN ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
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
void	RobotomyRequestForm::action() const
{
	std::cout << "Drillig noises..." << std::endl;
	unsigned int i = (unsigned int)std::rand();
	if (i % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed" << std::endl;
}



/* ************************************************************************** */
