/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:34:03 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/16 23:36:01 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 2147483647};
    std::cout << "Array of integers: ";
    iter(intArray, 5, printElement);
    std::cout << std::endl;
    iter(intArray, 5, sumOneToElement);
    iter(intArray, 5, printElement);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Array of doubles: ";
    iter(doubleArray, 5, printElement);
    std::cout << std::endl;
    iter(doubleArray, 5, sumOneToElement);
    iter(doubleArray, 5, printElement);
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Array of characters: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;
    iter(charArray, 5, sumOneToElement);
    iter(charArray, 5, printChar);
    std::cout << std::endl;

    char* charNull = NULL;
    std::cout << "Array of characters: ";
    iter(charNull, 5, printChar);
    std::cout << std::endl;
    iter(charNull, 5, sumOneToElement);
	
	//Just one curious case
    // char charArray[] = {'a', 'b', 'c', 'd', 'e', 126, 127, 128};
    // std::cout << "Array of characters: ";
    // iter(charArray, 8, printChar);
    // std::cout << std::endl;
    // iter(charArray, 8, sumOneToElement);
    // iter(charArray, 8, printChar);
    // std::cout << std::endl;
    return 0;
}

