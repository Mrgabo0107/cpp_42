/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:26:44 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/08 23:54:35 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{
	public:
		Weapon(std::string WeaponType);
		~Weapon(void);
		const std::string&	getType(void);
		void setType(std::string newWeapon);

	private:
		std::string	type;    
};

#endif