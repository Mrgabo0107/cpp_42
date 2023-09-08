/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:26:41 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/08 05:02:36 by gamoreno         ###   ########.fr       */
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
		std::istringstream		streamLine(line);
		std::string				dateString;
		double					rate;
		BitcoinExchange::date	dateKey;

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
		if (!BitcoinExchange::dateStringToDate(dateString, dateKey)) {
			std::cerr << "Error filling date struct" << std::endl;
			exit (4);
		}
		_data[dateKey] = rate;
	}
	//for debug
	// for(std::map<BitcoinExchange::date, double>::iterator it = _data.begin();
	// 	it != _data.end(); ++it) {
	// 	std::cout << it->first.year << '/' << it->first.month << '/'
	// 	<< it->first.day << '#' << it->second << std::endl;
	// }
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

std::string	BitcoinExchange::elimWhitespaces(const std::string& string) {
	std::string result = string;
	result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
	return result;
}

bool	BitcoinExchange::dateStringToDate(std::string dateString,
		BitcoinExchange::date &dateStruct) {
	std::istringstream		dateStringStream(dateString);
	std::string				auxString;

	if (std::getline(dateStringStream, auxString, '-')) {
		char		*endptr;

		long int aux = strtol(auxString.c_str(), &endptr, 10);
		if (*endptr != '\0')
			return false;
		if (aux < 0 || aux > UINT_MAX)
			return false;
		dateStruct.year = static_cast<unsigned int>(aux);
	}
	else
		return false;
	if (std::getline(dateStringStream, auxString, '-')) {
		char		*endptr;

		long int aux = strtol(auxString.c_str(), &endptr, 10);
		if (*endptr != '\0')
			return false;
		if (0 >= aux || aux > UINT_MAX)
			return false;
		dateStruct.month = static_cast<unsigned int>(aux);
	}
	else
		return false;
	if (std::getline(dateStringStream, auxString)) {
		char		*endptr;

		long int aux = strtol(auxString.c_str(), &endptr, 10);
		if (*endptr != '\0')
			return false;
		if (aux < 0 || aux > UINT_MAX)
			return false;
		dateStruct.day = static_cast<unsigned int>(aux);
	}
	else
		return false;
	return true;
}

bool	BitcoinExchange::isLeapYear(unsigned int year) {
	if (year % 4 == 0 && (!(year % 100 == 0) || (year % 400 == 0)))
		return true;
	return false;
}

bool	BitcoinExchange::isValidDate(const BitcoinExchange::date &currDate)
{
	if (((currDate.month == 1 || currDate.month == 3 ||
		currDate.month == 5 || currDate.month == 7 ||
		currDate.month == 8 || currDate.month == 10 ||
		currDate.month == 12) && (0 >= currDate.day || currDate.day > 31)) ||
		((currDate.month == 4 || currDate.month == 6 ||
		currDate.month == 9 || currDate.month == 11) &&
		(0 >= currDate.day || currDate.day > 30)) ||
		(currDate.month == 2 && ((BitcoinExchange::isLeapYear(currDate.year) &&
		(0 >= currDate.day || currDate.day > 29)) ||
		(!BitcoinExchange::isLeapYear(currDate.year) &&
		(0 >= currDate.day || currDate.day > 28)))))
		return false;
	return true;
}
bool	BitcoinExchange::isValidAmount(std::string amountString, float &currAmount) {
	char*	endptr;
	currAmount = strtof(amountString.c_str(), &endptr);
	if (*endptr != '\0') {
		std::cerr << "Error reading amount in input file" << std::endl;
		return false;
	}
	if (currAmount <= 0) {
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	if (currAmount > 1000) {
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::showActualValue(const std::string &dateString, 
		const date &currDate, const float &currAmount) {
	std::map<BitcoinExchange::date, double>::iterator it = _data.begin();
	
	if (currDate < it->first) {
		std::cerr << "Error: date before the first in the database" << std::endl;
	}
	while (it != _data.end() && it->first < currDate)
		it++;
	std::cout << dateString << " => " << currAmount << " = "
	<< it->second * currAmount << std::endl;
}

void	BitcoinExchange::executeBitcoinExchange(std::string inputPath)
{
	std::ifstream inputFile(inputPath.c_str());
	if (!inputFile) {
		std::cerr << "Error: could not open input file." << std::endl;
		exit (5);
	}
	
	std::string line;
	bool		ctrl = true;
	while (std::getline(inputFile, line)) {
		std::string pureLine = BitcoinExchange::elimWhitespaces(line);
		size_t pos = pureLine.find('|');
		if (pos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::istringstream		streamLine(pureLine);
		std::string				dateString;
		std::string				amountString;
		BitcoinExchange::date	currDate;
		float					currAmount;
		if (std::getline(streamLine, dateString, '|')) {
			if (dateString == "date" && ctrl)
				continue;
			if (!BitcoinExchange::dateStringToDate(dateString, currDate)
				|| !BitcoinExchange::isValidDate(currDate))
			{
				std::cout << "Error: bad date => " << dateString << std::endl;
				continue;
			}
			amountString = pureLine.c_str() + streamLine.tellg();
			if (!BitcoinExchange::isValidAmount(amountString, currAmount))
				continue;
			BitcoinExchange::showActualValue(dateString, currDate, currAmount);
		}
		else
			std::cerr << "Error reading date in input file." << std::endl;
		ctrl = false;
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