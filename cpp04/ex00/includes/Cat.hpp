/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:22:57 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 06:03:14 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{

	public:
		//Constructors
		Cat();
		Cat(const Cat &src);
		
		//Destructor
		~Cat();

		//Assignation
		Cat&	operator=(const Cat &rhs);

		//Methods
		void	makeSound() const;

};

#endif /* ************************************************************* CAT_H */