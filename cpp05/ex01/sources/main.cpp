/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:41:59 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/08 23:30:03 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form *SignHigh;
	Form *SignLow;
	Form *ExecHigh;
	Form *ExecLow;
	std::cout << "\n----------------------------------------------" 
	<< "\nInitialization form with high grade to sign:\n" 
	<< "----------------------------------------------"<< std::endl;
	try
	{
		SignHigh = new Form("test", 0, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	(void)SignHigh;
	std::cout << "\n----------------------------------------------" 
	<< "\nInitialization of form with low grade to sign:\n" 
	<< "----------------------------------------------"<< std::endl;
	try
	{
		SignLow = new Form("test", 151, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	(void)SignLow;
	std::cout << "\n----------------------------------------------" 
	<< "\nInitialization of form with high grade to execute:\n" 
	<< "----------------------------------------------"<< std::endl;
	try
	{
		ExecHigh = new Form("test", 10, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	(void)ExecHigh;
	std::cout << "\n----------------------------------------------" 
	<< "\nInitialization of form with low grade to execute:\n" 
	<< "----------------------------------------------"<< std::endl;
	try
	{
		ExecLow = new Form("test", 151, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	(void)ExecLow;
	
	std::cout << "\n----------------------------------------------" 
	<< "\nInitialization of good Form:\n" 
	<< "----------------------------------------------"<< std::endl;
	
	Form Clas("Clasified Form", 10, 3);
	std::cout << Clas << std::endl;
	
	Bureaucrat	CEO("Elon Zuckemberg", 1);
	Bureaucrat	Assistant("Pepo Cepeda", 100);
	Bureaucrat	Manager("Peda Cepepo", 10);

	std::cout << "\n----------------------------------------------" 
	<< "\nWith the following bureaucrats:\n" 
	<< "----------------------------------------------"<< std::endl;
	std::cout << CEO << "\n" << Assistant << "\n" << Manager << std::endl;
	
	std::cout << "\n----------------------------------------------" 
	<< "\nLow grade trying to sign:\n" 
	<< "----------------------------------------------"<< std::endl;
	Assistant.signForm(Clas);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nGood grade signing:\n" 
	<< "----------------------------------------------"<< std::endl;
	Manager.signForm(Clas);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nTrying to sign again:\n" 
	<< "----------------------------------------------"<< std::endl;
	CEO.signForm(Clas);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nTesting copy constructor:\n" 
	<< "----------------------------------------------"<< std::endl;
	Form copy(Clas);
	std::cout << "Original:\n" << Clas << std::endl;
	std::cout << "Copy:\n" << copy << std::endl;
	
	return (0);
}