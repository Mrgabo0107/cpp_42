/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:55:18 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/09 00:04:24 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string WeaponType) : type(WeaponType)
{
	
}

Weapon::~Weapon(void)
{

}

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string newWeapon)
{
	type = newWeapon;
}