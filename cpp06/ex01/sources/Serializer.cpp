/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:10:55 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/15 21:10:56 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
** ------------------------------- CONTEXTUAL GARBAGE --------------------------------
*/

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

void Serializer::printData(Data* data)
{
	std::cout << "inside the data pointed by "
	<< &data << ":\n"
	<< "value: " << data->value << '\n'
	<< "character: " << data->character << '\n'
	<< "string: " << data->string << std::endl;
}
/* ************************************************************************** */
