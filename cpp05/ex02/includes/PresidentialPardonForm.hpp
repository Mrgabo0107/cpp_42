#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	private:

};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);
