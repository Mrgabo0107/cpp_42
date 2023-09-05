/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:26:41 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/06 01:11:40 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange(std::string dataPath)
{
	std::ifstream bitcoinData(dataPath.c_str());
	if (!bitcoinData.is_open()) {
		std::cerr << "Error: could not open data file." << std::endl;
		exit(1);
	}

	std::string line;
	while (std::getline(bitcoinData, line)) {
		std::istringstream streamLine(line);
		std::string date;
		double rate;
		if (std::getline(streamLine, date, ',')) {
			if (date == "date")
				continue;
			const char* charNumber = line.c_str() + streamLine.tellg();
			char* endptr;
			rate = strtod(charNumber, &endptr);
			if (*endptr != '\0') {
				std::cerr << "Error reading rate in data file." << std::endl;
				exit (3);
			}
		}
		else {
			std::cerr << "Error reading date in data file." << std::endl;
			exit (2);
		}
		_data[date] = rate;
	}
	bitcoinData.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	_data = src.getData();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{}

/*
** --------------------------------- ASSIGN ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		_data = rhs.getData();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	BitcoinExchange::executeBitcoinExchange(std::string inputPath)
{
	(void)inputPath;
}

/*
** --------------------------------- ACCESSORS ----------------------------------
*/
const std::map<std::string, double>	&BitcoinExchange::getData() const {
	return this->_data;
}
/* ************************************************************************** */