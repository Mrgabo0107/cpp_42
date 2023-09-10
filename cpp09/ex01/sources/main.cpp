/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 01:58:17 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/10 11:35:15 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** ag) {
	if (ac != 2) {
		std::cout << "Usage: " << ag[0] << " \"RPN expression\"" << std::endl;
		return 1;
	}
	
	RPN rpnSolver;
	try {
		rpnSolver = RPN(ag[1]);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	if (rpnSolver.getStackSize() == 1)
		std::cout << rpnSolver.getResult() << std::endl;
	return 0;
}
