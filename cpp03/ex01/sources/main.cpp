/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:35:18 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/26 21:01:47 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"


int main(void)
{
	{
		std::cout << "Testing Orthodox Canonical Form" << std::endl
				  << std::endl;
		ScavTrap first;
		std::cout << "Info of first object initialized by default: \n"
				  << first << std::endl;
		ScavTrap second("ScavRobot");
		std::cout << "Info of second object initialized with a name: \n"
				  << second.getName() << std::endl;
		first = second;
		std::cout << "After assigning the second object to the first: \n"
				  << first << std::endl;
		ScavTrap third(second);
		std::cout << "A third object like a copy of second object: \n"
				  << third << std::endl;
	}
	{
		std::cout << "\n ********************************************************** \n"
				  << std::endl;
		std::cout << "Testing member functions" << std::endl;
		ScavTrap first("Robot1");
		std::cout << "Robot1's info: \n"
				  << first << std::endl;
        for (int i = 0; i < 25; i++)
        {
		    first.attack("target");
        }
        std::cout << "Info control: \n"
				  << first << std::endl;
        for (int i = 0; i < 22; i++)
        {
		    first.attack("target");
        }
		std::cout << "Info control before been repaired: \n"
				  << first << std::endl;
		first.beRepaired(2);
		std::cout << "Info control after been repaired: \n"
				  << first << std::endl;
        for (int i = 0; i < 3; i++)
        {
		    first.attack("target");
        }
		std::cout << "Last info check: \n"
				  << first << std::endl;
	}
	{
		std::cout << "\n ********************************************************** \n"
				  << std::endl;
		ScavTrap Tom("Tom");
		ScavTrap Clark("Clark");
		ScavTrap Putin("HPutin");

        Tom.guardGate();
        Clark.guardGate();
        Putin.guardGate();
		Tom.attack("Jerry");
		Clark.attack("Lex");
		Putin.attack("Zele");
		Tom.takeDamage(5);
		Clark.takeDamage(9);
		Putin.takeDamage(1000);
		Tom.beRepaired(10);
		std::cout << "Clark's status: \n"
				  << Clark << std::endl;
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
        Tom.guardGate();
        Clark.guardGate();
        Putin.guardGate();
	}
	return 0;
}
