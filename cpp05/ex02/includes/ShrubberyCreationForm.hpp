#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	private:

};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i);
