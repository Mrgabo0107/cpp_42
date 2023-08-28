/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:37:37 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/24 16:32:57 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int main() {
	//Vector
	{
		std::cout << "Vector:" << std::endl;
		std::vector<int> numbers;
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(15);
		numbers.push_back(20);
		numbers.push_back(25);

		int target = 25;
		std::vector<int>::iterator result = easyfind(numbers, target);
		if (result != numbers.end())
			std::cout << "Value " << target << " found at index: " << std::distance(numbers.begin(), result) << std::endl;
		else
			std::cout << "Value " << target << " not found." << std::endl;
	//with const copy
		std::cout << "Const vector:" << std::endl;
		const std::vector<int> copy(numbers);
		target = 20;
		std::vector<int>::const_iterator constResult = easyfind(copy, target);
		if (constResult != copy.end())
			std::cout << "Value " << target << " found at index: " << std::distance(copy.begin(), constResult) << std::endl;
		else
			std::cout << "Value " << target << " not found." << std::endl;
	}
	//List
	{
		std::cout << "List:" << std::endl;
		std::list<int> numbers;
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(15);
		numbers.push_back(20);
		numbers.push_back(25);
	
		int target = 5;
		std::list<int>::iterator result = easyfind(numbers, target);
	
		if (result != numbers.end())
			std::cout << "Value " << target << " found at index: " << std::distance(numbers.begin(), result) << std::endl;
		else
			std::cout << "Value " << target << " not found." << std::endl;
	}
	//Deque
	{
		std::cout << "Deque:" << std::endl;
		std::deque<int> numbers;
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(15);
		numbers.push_back(20);
		numbers.push_back(25);
	
		int target = 8;
		std::deque<int>::iterator result = easyfind(numbers, target);
	
		if (result != numbers.end()) {
			std::cout << "Value " << target << " found at index: " << std::distance(numbers.begin(), result) << std::endl;
		}
		else {
			std::cout << "Value " << target << " not found." << std::endl;
		}
	}
	return 0;
}
