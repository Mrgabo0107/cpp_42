/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:45:52 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/26 20:05:35 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include <climits>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		//Constructors	
		ScavTrap();
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap &src);

		//Assignation
		ScavTrap&	operator=(ScavTrap const &rhs);

		//Destructor
		~ScavTrap();

		//Methods
		void attack(const std::string &target);
		void guardGate(void);
};

std::ostream&	operator<<(std::ostream &o, ScavTrap const &i);

#endif /* ******************************************************** SCAVTRAP_H */