/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:37:14 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/09 01:09:14 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& currWeapon)
: _name(humanName), _Weapon(&currWeapon)
{
	
}

HumanA::~HumanA(void)
{
	
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
	return;
}