/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:10:52 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/15 21:10:53 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
	int value;
	char character;
	std::string string;
};

class Serializer
{

	public:
		//Contextual_garbage
		Serializer();
		Serializer(Serializer const &src);
		~Serializer();
		Serializer &operator=(Serializer const &rhs);

		//Methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		static void			printData(Data* ptr);
};

#endif /* ****************************************************** SERIALIZER_H */
