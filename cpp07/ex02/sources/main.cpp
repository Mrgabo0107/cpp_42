/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:34:03 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/24 16:05:11 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int main() {
	//Testing empty array
	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
		
	//testing with an int array
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); ++i) {
		intArray[i] = i * 2;
		std::cout << intArray[i] << " ";
    }
	std::cout << std::endl;

	//testing const array
	const Array<int> constTest(intArray);
	for (size_t i = 0; i < constTest.size(); ++i) {
		std::cout << constTest[i] << " ";
    }
	std::cout << std::endl;
	
	try {
		int outOfBounds = intArray[10];
		(void)outOfBounds;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	//testing copy constructor
	Array<int> intCopy(intArray);
	for (size_t i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	//Another type	
	Array<char> charArray(10);
	for (size_t i = 0; i < charArray.size(); ++i) {
		charArray[i] = (i + 33);
		std::cout << "\'" << charArray[i] << "\' ";
	}
	std::cout << std::endl;
	
	try {
		char outOfBounds = charArray[11];
		(void)outOfBounds;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	Array< Array<int> > intArrayArray(4);
	Array<int> auxIntArray(4);
	
	for (size_t i = 0; i < intArrayArray.size(); ++i) {
		intArrayArray[i] = auxIntArray;
		for (size_t j = 0; j < auxIntArray.size(); ++j) {
			intArrayArray[i][j] = i + j;
			std::cout << intArrayArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}