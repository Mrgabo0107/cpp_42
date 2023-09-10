/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 01:58:09 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/10 11:36:17 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
RPN::RPN()
{}

RPN::RPN(const char *input)
{
	_expression = input;
	if (_expression.find_first_not_of("0123456789*/-+ ") != std::string::npos)
		throw std::invalid_argument("Error: invalid characters in input");
	if (!noConsecutiveNonSpaceCharacters(_expression))
		throw std::invalid_argument("Error: All character in input has to be separated by at least one space");
	RPN::evaluateRPN();
}

RPN::RPN(RPN const &src)
{
	_expression = src._expression;
	_stack = src._stack;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{}


/*
** --------------------------------- ASSIGN ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		_expression = rhs._expression;
		_stack = rhs._stack;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool	RPN::noConsecutiveNonSpaceCharacters(const std::string &str) {
	for (size_t i = 0; i < str.length() - 1; ++i) {
		if (str[i] != ' ' && str[i + 1] != ' ')
			return false;
	}
	return true;
}

bool	RPN::isOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int		RPN::calculate(int operand1, int operand2, const std::string& op) {
	if (op == "+") return operand1 + operand2;
	if (op == "-") return operand1 - operand2;
	if (op == "*") return operand1 * operand2;
	if (op == "/") return operand1 / operand2;
	return 0;
}

void	RPN::evaluateRPN() {
	std::istringstream iss(_expression);
	std::string token;

	while (iss >> token) {
		if (!RPN::isOperator(token)) {
			int num;
			std::stringstream(token) >> num;
			_stack.push(num);
		} else {
			if (_stack.size() < 2) {
				throw std::invalid_argument("Error: at some point, the stack runs out of operands for an operation.");
			}
			int operand2 = _stack.top();
			_stack.pop();
			int operand1 = _stack.top();
			_stack.pop();
			_stack.push(RPN::calculate(operand1, operand2, token));
		}
	}
	if (_stack.size() != 1) {
		throw std::invalid_argument("Error: more than one number in the stack at the end of operations.");
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
int	RPN::getResult() const {
	return _stack.top();
}

int	RPN::getStackSize() const {
	return _stack.size();
}

/* ************************************************************************** */