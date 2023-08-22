/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:25:31 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/23 01:04:10 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

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

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] elements;
		elements = new T[other.arraySize];
		arraySize = other.arraySize;
		for (size_t i = 0; i < arraySize; ++i) {
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= arraySize) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= arraySize) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
size_t Array<T>::size() const {
	return arraySize;
}

#endif