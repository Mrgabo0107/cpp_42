/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:25:33 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/18 21:51:35 by gamoreno         ###   ########.fr       */
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
		Array& operator=(const Array& other);
		~Array();
		T& operator[](size_t index);
		size_t size() const;
};

# include "array.tpp"

#endif