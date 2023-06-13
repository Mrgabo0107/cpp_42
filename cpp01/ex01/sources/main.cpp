/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:45:24 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/06 23:28:07 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void    usageMessage(void)
{
	std::cout << "Please enter as a parameter the number of zombies to create." \
	<< std::endl;
	return;
}

bool	checkOnlyNumbers(std::string arg)
{
	if (arg.find_first_not_of("0123465789") < arg.size())
		return false;
	return true;
}

int	ManyZombiesMessage(void)
{
	std::cout << "Those are many zombies, avoid creating an apocalypse by";
	std::cout << std::endl;
	std::cout << "choosing a smaller number of zombies to create.";
	std::cout << std::endl;
	std::cout << std::endl;
	usageMessage();
	return (0);
}

int main(int ac, char **ag)
{
    if (ac == 2)
	{
		std::string	parameter = ag[1];
		if (checkOnlyNumbers(parameter))
		{
			if (parameter.size() >= 6)
				return(ManyZombiesMessage());
			int number = 0;
			std::istringstream(parameter) >> number;
			Zombie *horde = zombieHorde(number, "ZoMbIe");
			std::cout << "Each zombie says:" << std::endl;
			for (int i = 0; i < number; i++)
			{
				std::cout << "Zombie #" << i + 1 << ":";
				horde[i].announce();
			}
			delete[] horde;
		}
		else
		{
			usageMessage();
			return (0);
		}
	}
    else
		usageMessage();
    return (0);
}