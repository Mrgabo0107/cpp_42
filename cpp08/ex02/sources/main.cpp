/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:37:37 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/28 18:45:06 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	// Provided by school with message
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << "top after insert 5 et 17:\n"
		<< mstack.top() << std::endl;
		mstack.pop();
		
		std::cout << "size after do pop:\n"
		<< mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(7);
		mstack.push(737);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "after push 3, 7 and 737 and define \"it\" as the begin,\n"
		<< "and \"ite\" as the end of the stack\n\nit = "
		<< *it << std::endl;
		++it;
		std::cout << "after ++it, it = " << *it << std::endl;
		--it;
		std::cout << "returning to the begin with --it, it = " << *it << std::endl;
		std::cout << "now the stack is shown:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		//doing a parent class copy:
		std::stack<int> s(mstack);
		//trying to initializate a iterator who cannot be initialized:
		// try
		// {
			// std::stack<int>::iterator badit = s.begin();
		// }
		// catch(const std::exception& e)
		// {
			// std::cerr << e.what() << '\n';
		// }
	}
	// MutantStack of strings:
	{
		MutantStack<std::string> stringMStack;
		MutantStack<std::string>::iterator it = stringMStack.begin();
		std::cout << "after create "
	}
	
	return 0;
}