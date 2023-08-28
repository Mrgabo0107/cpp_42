/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:09:28 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/24 16:27:03 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

#include "easyFind.tpp"

#endif 