/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:26:41 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/06 16:31:06 by gamoreno         ###   ########.fr       */
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
		std::string dateString;
		double rate;
		if (std::getline(streamLine, dateString, ',')) {
			if (dateString == "date")
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
		_data[BitcoinExchange::dateStringToDate(dateString)] = rate;
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

BitcoinExchange::date	BitcoinExchange::dateStringToDate(std::string dateString) {
	std::istringstream		dateStringStream(dateString);
	std::string				auxString;
	BitcoinExchange::date	dateReturn;

	if (std::getline(dateStringStream, auxString, '-')) {
		char		*endptr;

		long int aux = strtol(auxString.c_str(), &endptr, 10);
		if (*endptr != '\0') {
			std::cerr << "Error reading year in dateString." << std::endl;
			exit (4);
		}
		if (aux < 0 || aux > UINT_MAX) {
			std::cerr << "Error reading year in dateString." << std::endl;
			exit (4);
		}
		dateReturn.year = static_cast<unsigned int>(aux);
	}
	else {
		std::cerr << "Error reading year in dateString." << std::endl;
		exit (4);
	}
	if (std::getline(dateStringStream, auxString, '-')) {
		char		*endptr;

		long int aux = strtol(auxString.c_str(), &endptr, 10);
		if (*endptr != '\0') {
			std::cerr << "Error reading month in dateString." << std::endl;
			exit (5);
		}
		if (0 >= aux || aux > UINT_MAX) {
			std::cerr << "Error reading month in dateString." << std::endl;
			exit (5);
		}
		dateReturn.month = static_cast<unsigned int>(aux);
	}
	else {
		std::cerr << "Error reading month in dateString." << std::endl;
		exit (5);
	}
	if (std::getline(dateStringStream, auxString)) {
		char		*endptr;

		long int aux = strtol(auxString.c_str(), &endptr, 10);
		if (*endptr != '\0') {
			std::cerr << "Error reading day in dateString." << std::endl;
			exit (6);
		}
		if (aux < 0 || aux > UINT_MAX) {
			std::cerr << "Error reading day in dateString." << std::endl;
			exit (6);
		}
		dateReturn.day = static_cast<unsigned int>(aux);
	}
	else {
		std::cerr << "Error reading day in dateString." << std::endl;
		exit (6);
	}
	return dateReturn;
}

void	BitcoinExchange::executeBitcoinExchange(std::string inputPath)
{
	std::ifstream inputFile(inputPath);
	if (!inputFile) {
		std::cerr << "Error: could not open input file." << std::endl;
		return 1;
	}
	
	std::string line;
	while (std::getline(inputFile, line)) {
		std::istringstream	streamLine(line);
		std::string			dateLine;
		std::string			amountLine;
		if () {}
		else { 
			std::cerr << "Error reading date in input file." << std::endl;
			exit (2);
		}
	}
}

bool BitcoinExchange::date::operator<(const date& other) const {
	if (year != other.year) {
		return year < other.year;
	}
	if (month != other.month) {
		return month < other.month;
	}
	return day < other.day;
}

bool BitcoinExchange::date::operator==(const date& other) const {
	return year == other.year && month == other.month && day == other.day;
}

/*
** --------------------------------- ACCESSORS ----------------------------------
*/
const std::map<BitcoinExchange::date, double>	&BitcoinExchange::getData() const {
	return this->_data;
}
/* ************************************************************************** */