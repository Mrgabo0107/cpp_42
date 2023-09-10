/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 01:58:07 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/10 11:34:05 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
	public:
		RPN();
		RPN(const char *input);
		RPN(RPN const &src);
		~RPN();
		RPN &operator=(RPN const &rhs);
		
		int	getResult() const;
		int	getStackSize() const;

	private:
		std::string		_expression;
		std::stack<int>	_stack;

		bool	noConsecutiveNonSpaceCharacters(const std::string &str);
		bool	isOperator(const std::string& token);
		int		calculate(int operand1, int operand2, const std::string& op);
		void	evaluateRPN();
};

#endif /* ************************************************************* RPN_H */