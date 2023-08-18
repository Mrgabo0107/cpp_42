/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:25:33 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/17 22:57:26 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T* elements;
		size_t arraySize;
	
	public:
		Array();
		explicit Array(unsigned int n);
		Array(const Array& other);
	
		Array& operator=(const Array& other) {
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
	
		~Array() {
			delete[] elements;
		}
	
		T& operator[](size_t index) {
			if (index >= arraySize) {
				throw std::out_of_range("Index out of bounds");
			}
			return elements[index];
		}
	
		size_t size() const {
			return arraySize;
		}
}

# include "array.tpp"

#endif