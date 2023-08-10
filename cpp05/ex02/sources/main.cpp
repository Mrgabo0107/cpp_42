/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:07:50 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/10 09:52:09 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat	CEO("Elon Zuckemberg", 1);
	Bureaucrat	Assistant("Pepo Cepeda", 150);
	Bureaucrat	Manager("Mark Musk", 10);

	std::cout << "\n----------------------------------------------" 
	<< "\nWith the following bureaucrats:\n" 
	<< "----------------------------------------------"<< std::endl;
	std::cout << CEO << "\n" << Assistant << "\n" << Manager << std::endl;
	
	std::cout << "\n----------------------------------------------" 
	<< "\nInitializing Shrubbery Creation Form:\n" 
	<< "----------------------------------------------"<< std::endl;
    ShrubberyCreationForm Form1("heaven");
    std::cout << Form1 << std::endl;
	
    std::cout << "\n----------------------------------------------" 
	<< "\nTrying to execute from CEO without signing:\n" 
	<< "----------------------------------------------"<< std::endl;
    CEO.executeForm(Form1);
    
    std::cout << "\n----------------------------------------------" 
	<< "\nTrying to sign from Assitant:\n" 
	<< "----------------------------------------------"<< std::endl;
	Assistant.signAForm(Form1);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nSigning from Manager:\n" 
	<< "----------------------------------------------"<< std::endl;
	Manager.signAForm(Form1);
	
    std::cout << "\n----------------------------------------------" 
	<< "\nTrying to execute from Assistant:\n" 
	<< "----------------------------------------------"<< std::endl;
	Assistant.executeForm(Form1);

    std::cout << "\n----------------------------------------------" 
	<< "\nExecution from Manager:\n" 
	<< "----------------------------------------------"<< std::endl;
    Manager.executeForm(Form1);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nInitializing Robotomy Request Form:\n" 
	<< "----------------------------------------------"<< std::endl;
    RobotomyRequestForm Form2("Bender");
    std::cout << Form2 << std::endl;
	
	std::cout << "\n----------------------------------------------" 
	<< "\nSigning from Manager:\n" 
	<< "----------------------------------------------"<< std::endl;
	Manager.signAForm(Form2);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nCEO looping over 10 Benders to check the average of succes:\n"
	<< "----------------------------------------------"<< std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Try number " << i + 1 << ":" << std::endl;
		CEO.executeForm(Form2);
		std::cout << std::endl;
	}
	
	std::cout << "\n----------------------------------------------" 
	<< "\nInitializing Presidential Pardon Form:\n" 
	<< "----------------------------------------------"<< std::endl;
    PresidentialPardonForm Form3("Arthur Dent");
    std::cout << Form3 << std::endl;
	
	std::cout << "\n----------------------------------------------" 
	<< "\nSigning from Manager:\n" 
	<< "----------------------------------------------"<< std::endl;
	Manager.signAForm(Form3);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nManager trying to execute:\n" 
	<< "----------------------------------------------"<< std::endl;
	Manager.executeForm(Form3);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nCEO executing Presidential Pardon Form:\n" 
	<< "----------------------------------------------"<< std::endl;
	CEO.executeForm(Form3);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nTesting copy constructor:\n" 
	<< "----------------------------------------------"<< std::endl;
	std::cout << "Doing a copy of the Presidential Pardon Form from the last form used:"
	<< std::endl;
	PresidentialPardonForm copy1(Form3);
	std::cout << "Copy:\n" << copy1 << std::endl;
	std::cout << "From:\n" << Form3 << std::endl;

    return (0);
}