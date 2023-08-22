/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:27:04 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/22 06:00:30 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int N) : _maxCapacity(N) {}

Span::Span(const Span &src) : _numbers(src._numbers), _maxCapacity(src._maxCapacity) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() {}

/*
** --------------------------------- ASSIGN ---------------------------------
*/

Span& Span::operator=(Span const &rhs) {
	if (this != &rhs)
	{
		this->_numbers = rhs._numbers;
		this->_maxCapacity = rhs._maxCapacity;
	}
	return *this;
}

/*
** --------------------------------- ACCESOR ----------------------------------
*/
unsigned int Span::getMaxCapacity() const {
	return this-> _maxCapacity;
}

int Span::getNumberAt(size_t index) const {
	if (index >= _numbers.size()) {
		throw std::out_of_range("Índex out of range");
	}
	return (_numbers[index]);
}

const std::vector<int> &Span::getNumberVector() const {
	return this->_numbers;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int num) {
	if (_numbers.size() >= _maxCapacity)
		throw std::runtime_error("maximum capacity reached");
	_numbers.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _maxCapacity)
		throw std::runtime_error("maximum capacity reached");
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() <= 1)
		throw std::runtime_error("it takes at least two numbers to find an interval");	
	
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());	
	int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < sortedNumbers.size(); ++i) {
		int diff = sortedNumbers[i] - sortedNumbers[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan() {
	if (_numbers.size() <= 1)
		throw std::runtime_error("it takes at least two numbers to find an interval");
	return (*std::max_element(_numbers.begin(), _numbers.end()) \
	- *std::min_element(_numbers.begin(), _numbers.end()));
}

/*
** --------------------------------- STREAM ---------------------------------
*/

std::ostream &operator<<(std::ostream &o, Span const &i) {
	if (i.getNumberVector().size() > 0 && i.getNumberVector().size() < 11) {
		o << "Span members:\n";
		try {
			for (unsigned int index = 0; index < i.getNumberVector().size(); index++) {
				o << i.getNumberAt(index) << '\n';
			}
			return o;
		}
		catch (std::exception& e) {
			o << "error showing Span\n"; 
		}
	}
	else if (i.getNumberVector().size() > 0 && i.getNumberVector().size() >= 11){
		o << "Ten first Span members:\n";
		try {
			for (int index = 0; index < 10; index++) {
				o << i.getNumberAt(index) << '\n';
			}
			return o;
		}
		catch (std::exception& e){
			o << "error showing Span\n";
		}
	}
	else
		o << "nothing to show\n";
	return o;
}

/* ************************************************************************** */