/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:37:37 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/23 20:18:00 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int main() {
	//Vector
	{
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
	}
	//List
	{
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
