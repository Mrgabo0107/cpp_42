/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:40 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 00:53:23 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:
		//Constructors
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &src);
		
		//Destructor
		virtual ~Animal();

		//Assignation
		Animal&	operator=(const Animal &rhs);
		
		//Getter
		std::string	getType() const;

		//Methods
		virtual void makeSound() const;

	protected:
		std::string _type;
};

std::ostream&	operator<<(std::ostream &o, const Animal &i);

#endif /* ********************************************************** ANIMAL_H */