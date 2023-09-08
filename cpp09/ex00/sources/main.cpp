/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:19:07 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/08 03:22:38 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file\n" << "Usage: " << av[0]
		<< " input_file" << std::endl;
		return 1;
	}
	BitcoinExchange exchange("data.csv");
	exchange.executeBitcoinExchange(av[1]);
	return 0;
}


