/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:22:57 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 06:15:54 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

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
		void	printBrain() const;
		void	setBrain(std::string idea);
	
	private:
		Brain* _brain;
};

#endif /* ************************************************************* CAT_H */