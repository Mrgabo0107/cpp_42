/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:46:05 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/06 23:23:57 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class   Zombie
{
    public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	define_name(std::string	z_name);

	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif