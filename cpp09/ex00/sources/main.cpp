/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:19:07 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/06 01:14:23 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	BitcoinExchange exchange("data.csv");
	exchange.executeBitcoinExchange(av[1]);
	return 0;
}

// int main(int argc, char *argv[]) {






//     std::ifstream inputFile(argv[1]);
//     if (!inputFile) {
//         std::cerr << "Error: could not open input file." << std::endl;
//         return 1;
//     }

//     while (std::getline(inputFile, line)) {
//         std::istringstream iss(line);
//         std::string date;
//         double value;

//         if (iss >> date >> value) {
//             std::map<std::string, double>::iterator it = bitcoinPrices.lower_bound(date);
//             if (it == bitcoinPrices.begin()) {
//                 std::cerr << "Error: Date not found in database, using the closest available date." << std::endl;
//                 it = bitcoinPrices.begin();
//             } else if (it == bitcoinPrices.end()) {
//                 std::cerr << "Error: Date not found in database, using the closest available date." << std::endl;
//                 --it;
//             } else {
//                 std::map<std::string, double>::iterator prev = it;
//                 --prev;
//                 if (date > it->first && date < prev->first) {
//                     it = prev;
//                 }
//             }
//             const double exchangeRate = it->second;
//             std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (value * exchangeRate) << std::endl;
//         } else {
//             std::cerr << "Error: bad input format." << std::endl;
//         }
//     }

//     return 0;
// }
