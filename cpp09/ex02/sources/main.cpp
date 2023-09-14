/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:15:13 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/14 02:44:28 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **ag) {
	PmergeMe FordJhonson(ac, ag);

	if (ac > 1) {
		if (FordJhonson.solve())
			std::cout << FordJhonson << std::endl;
		else
			return 1;
	}
	return 0;
}