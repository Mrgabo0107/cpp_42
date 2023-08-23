/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:37:37 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/23 20:52:19 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	{
		Span sp = Span(11);
		Span spCopy(sp);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Span sp: \n" << sp << std::endl;
		std::cout << "Copy of span sp without inicialization: \n" << spCopy << std::endl;
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;

		int additionalNumbersArr[] = {20, 1, 8, -2, 14, -5};
		std::vector<int> additionalNumbers(additionalNumbersArr, additionalNumbersArr + sizeof(additionalNumbersArr) / sizeof(int));
		try {
			sp.addNumbers(additionalNumbers.begin(), additionalNumbers.end());
		}
		catch(const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Span sp after adding a set of numbers: \n" << sp << std::endl;
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "\nTrying to add more numbers than expected: " << std::endl;
		try {
		sp.addNumber(1);
		}
		catch(const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span hugeSp = Span(12000);
		std::vector<int> oneVector(6000, 1);
		std::vector<int> twoVector(6000, 2);
		hugeSp.addNumbers(oneVector.begin(), oneVector.end());
		hugeSp.addNumbers(twoVector.begin(), twoVector.end());
		std::cout << "\n\nhugeSp after adding two 6000 member sets of numbers: \n" << hugeSp << std::endl;
		std::cout << "ShortestSpan: " << hugeSp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << hugeSp.longestSpan() << std::endl;
	}
	return 0;
}


