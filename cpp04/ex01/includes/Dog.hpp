/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:49 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 06:24:07 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	
	public:
		//Constructors
		Dog();
		Dog(const Dog &src);

		//Destructor
		~Dog();

		//Assignation
		Dog&	operator=(const Dog &rhs);

		//Methods
		void	makeSound() const;
		void	printBrain() const;
		void	setBrain(std::string idea);
	
	private:
		Brain* _brain;
};

#endif /* ************************************************************* DOG_H */