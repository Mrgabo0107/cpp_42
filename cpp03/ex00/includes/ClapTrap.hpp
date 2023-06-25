/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:27:51 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/25 02:08:31 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <climits>

class ClapTrap
{

	public:
		//Constructors
		ClapTrap();
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap &src);
		
		//Assignation
		ClapTrap&	operator=(ClapTrap const &rhs);
		
		//Destructor
		~ClapTrap();

		//Getters
		std::string		getName(void) const;
		unsigned int	getHitPoint(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;

		//Setters
		void	setName(std::string newName);
		void	setHitPoint(unsigned int i);
		void	setEnergyPoint(unsigned int i);
		void	setAttackDamage(unsigned int i);
		
		//Methods
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;
};

#endif