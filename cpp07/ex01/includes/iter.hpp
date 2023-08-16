/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:30:56 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/16 23:32:15 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

void printChar(const char c)
{
    std::cout << c << " ";
}

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

template <typename T>
void sumOneToElement(T& element) {
    element += 1;
}

template <typename T>
void iter(T* array, size_t length, void (*function)(T&)) {
    if (!array) {
        std::cout << "invalid array" << std::endl;
        return ;
    }
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

template <typename T>
void iter(T* array, size_t length, void (*function)(T)) {
    if (!array) {
        std::cout << "invalid array" << std::endl;
        return ;
    }
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

#endif