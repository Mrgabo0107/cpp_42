/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:39:25 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/09 00:52:18 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	Slave1;
	Bureaucrat	CEO("Elon Zuckemberg", 1);

	std::cout << "\n----------------------------------------------" 
	<< "\nWith the CEO and two interns who create the forms:\n" 
	<< "----------------------------------------------"<< std::endl;
	std::cout << CEO << std::endl;
	

	AForm *shrubbery = Slave1.makeForm("Shrubbery", "night");
	std::cout << *shrubbery << std::endl;

	Intern Slave2(Slave1); //testing copy constructor

	AForm *robotomy = Slave2.makeForm("Robotomy", "R2D2");
	std::cout << *robotomy << std::endl;
	AForm *presidential = Slave1.makeForm("Presidential", "Vegeta");
	std::cout << *presidential << std::endl;
	std::cout << "\n----------------------------------------------" 
	<< "\nTrying bad form\n" 
	<< "----------------------------------------------"<< std::endl;
	AForm *clasified;
	try
	{
		clasified = Slave2.makeForm("Clasified", "X");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	(void)clasified;
	std::cout << "\n----------------------------------------------" 
	<< "\nSigning:\n" 
	<< "----------------------------------------------"<< std::endl;
	CEO.signAForm(*shrubbery);
	CEO.signAForm(*robotomy);
	CEO.signAForm(*presidential);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nChecking:\n" 
	<< "----------------------------------------------"<< std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;

	std::cout << "\n----------------------------------------------" 
	<< "\nExecuting:\n" 
	<< "----------------------------------------------"<< std::endl;
	CEO.executeForm(*shrubbery);
	CEO.executeForm(*robotomy);
	CEO.executeForm(*presidential);
	
	
	delete(shrubbery);
	delete(robotomy);
	delete(presidential);
    return (0);
}