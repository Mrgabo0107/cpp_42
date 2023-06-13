/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 00:48:56 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/09 00:54:21 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string humanName);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon& currWeapon);
	
    private:
		std::string	_name;
		Weapon*		_Weapon;
		
};
#endif