/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:41:51 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/08 19:22:38 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat* toHigh;
	Bureaucrat* toLow;

	std::cout << "----------------------------------------------" 
	<< "\nTest high declaration:\n" 
	<< "----------------------------------------------"<< std::endl;
	try
	{
		toHigh = new Bureaucrat("ToHigh", 0);
		std::cerr << "Exception does'nt work nicely." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	std::cout << "\n----------------------------------------------" 
	<< "\nTest low declaration:\n"
	<< "----------------------------------------------"<< std::endl;
	try
	{
		toLow = new Bureaucrat("ToLow", 420);
		std::cerr << "Exception does'nt work nicely." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	(void) toHigh;
	(void) toLow;

	Bureaucrat* bureaucrat = new Bureaucrat("Gabo", 2);
	Bureaucrat* stagiaire = new Bureaucrat("Pepe", 149);

	std::cout << "\n----------------------------------------------" 
	<< "\nTest valid and invalid upgrade:\n"
	<< "----------------------------------------------"<< std::endl;
	try
	{
		std::cout << *bureaucrat;
		bureaucrat->upGrade();
		std::cout << bureaucrat->getName() << " upgraded!" << std::endl;
		std::cout << *bureaucrat;
		bureaucrat->upGrade();
		std::cerr << "Exception does'nt work nicely. " << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	std::cout << "\n----------------------------------------------" 
	<< "\nTest valid and invalid downgrade:\n"
	<< "----------------------------------------------"<< std::endl;
	try
	{
		std::cout << *stagiaire;
		stagiaire->downGrade();
		std::cout << stagiaire->getName() << " downgraded!" << std::endl;
		std::cout << *stagiaire;
		stagiaire->downGrade();
		std::cerr << "Exception does'nt work nicely. " << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Expected exception: " << e.what() << std::endl;
	}
	delete bureaucrat;
	delete stagiaire;
	return (0);
}