/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:45:52 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/03 14:09:09 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <climits>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		//Constructors	
		FragTrap();
		FragTrap(std::string newName);
		FragTrap(const FragTrap &src);

		//Assignation
		FragTrap&	operator=(FragTrap const &rhs);

		//Destructor
		~FragTrap();

		//Methods
		void attack(const std::string &target);
		void highFivesGuy(void);
};

std::ostream&	operator<<(std::ostream &o, FragTrap const &i);

#endif /* ******************************************************** FRAGTRAP_H */