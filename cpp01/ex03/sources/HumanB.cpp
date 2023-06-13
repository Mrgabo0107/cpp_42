/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:54:45 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/09 01:08:45 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string humanName)
: _name(humanName)
{
	
}

HumanB::~HumanB(void)
{
	
}

void	HumanB::setWeapon(Weapon& currWeapon)
{
	_Weapon = &currWeapon;
	return;
}

void	HumanB::attack(void) const
{
	std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
	return;
}
