/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:09:59 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/24 16:26:06 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyFind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator result = std::find(container.begin(), container.end(), value);
	return result;
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
	typename T::const_iterator result = std::find(container.begin(), container.end(), value);
	return result;
}

#endif