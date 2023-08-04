/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:22:57 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 06:03:31 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:
		//Constructors
		WrongCat();
		WrongCat(const WrongCat &src);
		
		//Destructor
		~WrongCat();

		//Assignation
		WrongCat&	operator=(const WrongCat &rhs);
		void	makeSound() const;

};

#endif /* ************************************************************* WRONGCAT_H */