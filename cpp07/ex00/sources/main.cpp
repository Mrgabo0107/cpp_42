/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:34:03 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/22 20:37:43 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Templates.hpp"

int main(){
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// For testing non comparable classes
	// NoComparison obj1(5);
	// NoComparison obj2(10);
	
	// try {
	// 	NoComparison minObj = min(obj1, obj2);
	// 	NoComparison maxObj = max(obj1, obj2);
	// 	(void)minObj;
	// 	(void)maxObj;
	// }
	// catch (const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
	return 0;
}