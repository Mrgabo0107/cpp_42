/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:25:31 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/17 22:57:45 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_tpp

#include "array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), arraySize(n) {
	for (size_t i = 0; i < arraySize; ++i) {
		elements[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array& other) : elements(new T[other.arraySize]), arraySize(other.arraySize) {
	for (size_t i = 0; i < arraySize; ++i) {
	    elements[i] = other.elements[i];
	}
}
#endif