#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	private:

};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);
