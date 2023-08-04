/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:19:21 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 08:34:43 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	std::cout << "Test from subject:\n" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	std::cout << "*****************************************" << std::endl;
	std::cout << "\nArray test:\n" << std::endl;
	{
		Animal	*AnimalArray[6];
		
		for (int i = 0; i < 3; i++)
			AnimalArray[i] = new Dog();	
		for (int i = 3; i < 6; i++)
			AnimalArray[i] = new Cat();
		for (int i = 0; i < 6; i++)
			delete AnimalArray[i];
	}
	std::cout << "*****************************************" << std::endl;
	std::cout << "\nArray test for cats:\n" << std::endl;
	{
		std::cout << "\na creation:" << std::endl;
		Cat		a;
		std::cout << "\nb creation:" << std::endl;
		Cat		b;
		std::cout << "\nc creation as a assignation of a:" << std::endl;
		Cat		c = a;

		std::cout << "\na starts thinking about licking its paws" << std::endl;
		a.setBrain("lick my paws");
		std::cout << "\nA brain:\n";
		a.printBrain();
		std::cout << "\na assigned to b:\n";
		b = a;
		std::cout << "\nB brain:\n";
		b.printBrain();
		std::cout << "\nC brain:\n";
		c.printBrain();
		std::cout << "\nWith different thoughts...\n";
		c.setBrain("c brain");
		b.setBrain("b brain");
		a.setBrain("a brain");
		std::cout << "\nA brain:\n";
		a.printBrain();
		std::cout << "\nB brain:\n";
		b.printBrain();
		std::cout << "\nC brain:\n";
		c.printBrain();
		c.makeSound();
		a.makeSound();
		b.makeSound();
	}
	std::cout << "*****************************************" << std::endl;
	std::cout << "\nArray test for dogs:\n" << std::endl;
	{
		std::cout << "\na creation:" << std::endl;
		Dog		a;
		std::cout << "\nb creation:" << std::endl;
		Dog		b;
		std::cout << "\nc creation as a assignation of a:" << std::endl;
		Dog		c = a;

		std::cout << "\na starts thinking about playing ball" << std::endl;
		a.setBrain("play ball");
		std::cout << "\nA brain:\n";
		a.printBrain();
		std::cout << "\na assigned to b:\n";
		b = a;
		std::cout << "\nB brain:\n";
		b.printBrain();
		std::cout << "\nC brain:\n";
		c.printBrain();
		std::cout << "\nWith different thoughts...\n";
		c.setBrain("c brain");
		b.setBrain("b brain");
		a.setBrain("a brain");
		std::cout << "\nA brain:\n";
		a.printBrain();
		std::cout << "\nB brain:\n";
		b.printBrain();
		std::cout << "\nC brain:\n";
		c.printBrain();
		c.makeSound();
		a.makeSound();
		b.makeSound();
	}
	return 0;
}