/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:35:18 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/26 20:41:19 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main(void)
{
	{
		std::cout << "Testing Orthodox Canonical Form" << std::endl
				  << std::endl;
		ClapTrap first;
		std::cout << "Info of first object initialized by default: \n"
				  << first << std::endl;
		ClapTrap second("WeakRobot");
		std::cout << "Info of second object initialized with a name: \n"
				  << second.getName() << std::endl;
		first = second;
		std::cout << "After assigning the second object to the first: \n"
				  << first << std::endl;
		ClapTrap third(second);
		std::cout << "A third object like a copy of second object: \n"
				  << third << std::endl;
	}
	{
		std::cout << "\n ********************************************************** \n"
				  << std::endl;
		std::cout << "Testing member functions" << std::endl;
		ClapTrap first("RobotWhoCannotAttack");
		std::cout << "RobotWhoCannotAttack's info: \n"
				  << first << std::endl;
		first.attack("target1");
		first.attack("target2");
		first.attack("target3");
		first.attack("target4");
		first.attack("target5");
		std::cout << "Info control: \n"
				  << first << std::endl;
		first.attack("target6");
		first.attack("target7");
		first.attack("target8");
		first.attack("target9");
		std::cout << "Info control before been repaired: \n"
				  << first << std::endl;
		first.beRepaired(2);
		std::cout << "Info control after been repaired: \n"
				  << first << std::endl;
		first.attack("target10");
		first.attack("target11");
		std::cout << "Last info check: \n"
				  << first << std::endl;
	}
	{
		std::cout << "\n ********************************************************** \n"
				  << std::endl;
		ClapTrap Tom("Tom");
		ClapTrap Clark("Clark");
		ClapTrap Putin("HPutin");

		Tom.attack("Jerry");
		Clark.attack("Lex");
		Putin.attack("Zele");
		Tom.takeDamage(5);
		Clark.takeDamage(9);
		Putin.takeDamage(1000);
		Tom.beRepaired(10);
		Clark.takeDamage(4294967290);
		Putin.takeDamage(4294967295);
		std::cout << "Tom's status: \n"
				  << Tom << std::endl;
		std::cout << "Clark's status: \n"
				  << Clark << std::endl;
		std::cout << "Putin's status: \n"
				  << Putin << std::endl;
		Tom.beRepaired(4294967295);
		std::cout << "Tom's status: \n"
				  << Tom << std::endl;
		Tom.beRepaired(1);
		std::cout << "Tom's status: \n"
				  << Tom << std::endl;
	}
	return 0;
}
