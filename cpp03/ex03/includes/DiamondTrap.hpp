/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:36:30 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/04 18:50:01 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include <climits>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public virtual ClapTrap, public FragTrap, public ScavTrap
{

	public:
		//Constructors
		DiamondTrap();
		DiamondTrap(const std::string &newName);
		DiamondTrap(const DiamondTrap &src);
		
		//Assignation
		DiamondTrap&	operator=(DiamondTrap const &rhs);
		
		//Destructor
		~DiamondTrap();

		//Getter & Setter
		std::string		getName(void) const;
		void			setName(std::string newName);
		
		//Methods
		void attack(const std::string &target);
		void whoAmI(void);

	private:
		std::string	_name;

};

std::ostream&	operator<<(std::ostream &o, DiamondTrap const &i);

#endif /* ***************************************************** DIAMONDTRAP_H */