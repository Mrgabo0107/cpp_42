/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:34:03 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/18 22:09:02 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"


int main() {
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        int outOfBounds = intArray[10];
        (void)outOfBounds;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}