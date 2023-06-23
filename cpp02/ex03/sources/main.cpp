/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:41:55 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/23 20:52:59 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

void	usage(void)
{
	std::cout << std::endl;
	std::cout << "Enter the coordinates of four points in the plane to know\n"
	<< "if the fourth point is inside the triangle defined by the\n"
	<< "first three.\n"
	<< std::endl;
}

bool isFloat(const std::string& str)
{
    std::istringstream inputStream(str);
    float 				numero;
	
    return (inputStream >> numero) && (inputStream.eof());
}

float	fillCoor(std::string coor, std::string point)
{
	std::string	entry;
	float		number;
	
	while(1)
	{
		std::cout << "please enter a valid real number to fill the coordenate\n"
		<< coor << " of the " << point << " point" << std::endl;
		std::cin >> entry;
		if (isFloat(entry))
		{
			std::istringstream inputStream(entry);
            inputStream >> number;
			break;
		}
	}
	std::cout << "The " << coor << " coordinate of the " << point 
	<< " point was set to " << number << std::endl; 
	return (number);
}

int main(void)
{
	
	usage();
	Point a(fillCoor("x", "first"), fillCoor("y", "first"));
	Point b(fillCoor("x", "second"), fillCoor("y", "second"));
	Point c(fillCoor("x", "third"), fillCoor("y", "third"));
	Point p(fillCoor("x", "fourth"), fillCoor("y", "fourth"));
	if (bsp(a, b, c, p) == true)
		std::cout << "\nTHE POINT IS INSIDE THE TRIANGLE.\n" << std::endl;
	else
		std::cout << "\nTHE POINT IS OUTSIDE THE TRIANGLE.\n" << std::endl;
	return 0;
}