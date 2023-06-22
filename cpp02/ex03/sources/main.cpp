/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:41:55 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/23 00:00:59 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

int main( void )
{
	Point a(-3.98f, 0.56f);
	Point b(-4.26f, -6.8f);
	Point c(6.56f, 1.82f);
	Point p(-4.16f, -6.13f);

	if (bsp(a, b, c, p) == true)
		std::cout << "true" << std::endl;
	else if (bsp(a, b, c, p) == false)
		std::cout << "false" << std::endl;
	return 0;
}