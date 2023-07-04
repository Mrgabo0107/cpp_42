/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:35:18 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/04 19:36:29 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"


int main(void)
{
	{
		std::cout << "Testing Orthodox Canonical Form" << std::endl
				  << std::endl;
		DiamondTrap first;
		std::cout << "Info of first object initialized by default: \n"
				  << first << std::endl;
		
		std::cout << "first asking:" << std::endl;
		first.whoAmI();
		std::cout << std::endl;
		DiamondTrap second("DiamRobot");
		std::cout << "Info of second object initialized with a name: \n"
				  << second.getName() << second << std::endl;
		std::cout << "second asking:" << std::endl;
		second.whoAmI();
		std::cout << std::endl;
		std::cout << "first asking:" << std::endl;
		first.whoAmI();
		std::cout << std::endl;
		first = second;
		std::cout << "After assigning the second object to the first: \n"
				  << first << std::endl;
		std::cout << "first asking:" << std::endl;
		first.whoAmI();
		std::cout << std::endl;
		DiamondTrap third(second);
		std::cout << "A third object like a copy of second object: \n"
				  << third << std::endl;
		std::cout << "third asking:" << std::endl;
		third.whoAmI();
		std::cout << std::endl;
		std::cout << "second asking:" << std::endl;
		second.whoAmI();
		std::cout << std::endl;
		std::cout << "first asking:" << std::endl;
		first.whoAmI();
		std::cout << std::endl;
	}
	{
		std::cout << "\n ********************************************************** \n"
				  << std::endl;
		std::cout << "Testing member functions" << std::endl;
		DiamondTrap first("Diamond1");
		std::cout << "Diamond1's info: \n"
				  << first << std::endl;
		std::cout << "Diamond1 asking:" << std::endl;
		first.whoAmI();
		std::cout << std::endl;
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
		DiamondTrap Tom("Tom");
		DiamondTrap Clark("Clark");
		DiamondTrap Putin("HPutin");

        Tom.whoAmI();
        Clark.whoAmI();
        Putin.whoAmI();
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
        Tom.whoAmI();
        Clark.whoAmI();
        Putin.whoAmI();
	}
	return 0;
}
