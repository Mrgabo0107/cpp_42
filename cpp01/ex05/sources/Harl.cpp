/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:51:57 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/12 17:48:21 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
    
}

Harl::~Harl(void)
{
    
}

void    Harl::complain(std::string level)
{
    void    (Harl::*funcPointer[4]) (void) = {&Harl::debug, &Harl::info, \
                                        &Harl::warning, &Harl::error};
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

	while (i < 4)
	{
		if (level == options[i])
		{
			(this->*funcPointer[i])();
			break;
		}
		i++;
		if (i == 4)
		{
			std::cout << "The parameter doesn't match any option." << std::endl;
			Harl::usageMessage();
		}
	}
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my ";
    std::cout << "7XL-double-cheese-triple-picklespecial-ketchup burger. ";
    std::cout << "I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn’t put enough bacon in my burger! If you did, ";
    std::cout << "I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years whereas you started working ";
    std::cout << "here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
}

void    Harl::usageMessage(void)
{
	std::cout << "Launch this program with these four possible options:";
	std::cout << std::endl;
	std::cout << "DEBUG" << std::endl;
	std::cout << "INFO" << std::endl;
	std::cout << "WARNING" << std::endl;
	std::cout << "ERROR" << std::endl;
}