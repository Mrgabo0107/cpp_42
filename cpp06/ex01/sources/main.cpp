/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:29:13 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/16 01:28:34 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data dataInst;
	dataInst.value = 42;
	dataInst.character = '&';
	dataInst.string = "dlroW olleH";
	
	std::cout << "\n----------------------------------------------" 
	<< "\nInitial data:\n" 
	<< "----------------------------------------------"<< std::endl;
	Serializer::printData(&dataInst);
	uintptr_t serializedPtr = Serializer::serialize(&dataInst);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nFor curiosity, return of \"serialize\":\n" 
	<< "----------------------------------------------"<< std::endl;
	std::cout << serializedPtr << std::endl;
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);
	
	std::cout << "\n----------------------------------------------" 
	<< "\nData after \"deserialize\":\n" 
	<< "----------------------------------------------"<< std::endl;
	Serializer::printData(deserializedPtr);

	if (deserializedPtr == &dataInst)
	{
		std::cout << "\nDeserialization successful!" << std::endl;
	}
	else
	{
		std::cout << "\nDeserialization failed!" << std::endl;
	}
	return 0;
}