/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:21:40 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 01:38:14 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:
		//Constructors
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &src);
		
		//Destructor
		~WrongAnimal();

		//Assignation
		WrongAnimal&	operator=(const WrongAnimal &rhs);
		
		//Getter
		std::string	getType() const;

		//Methods
		void makeSound() const;

	protected:
		std::string _type;
};

std::ostream&	operator<<(std::ostream &o, const WrongAnimal &i);

#endif /* ********************************************************** WRONGANIMAL_H */