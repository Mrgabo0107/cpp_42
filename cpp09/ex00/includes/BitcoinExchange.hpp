/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:12:27 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/09 01:53:13 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <climits>
# include <algorithm>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string dataPath);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void	executeBitcoinExchange(std::string inputPath);
		
		struct date {
			unsigned int year;
			unsigned int month;
			unsigned int day;

			bool operator<(const date& other) const;
			bool operator==(const date& other) const;
			bool operator<=(const date& other) const;
		};
		
		const std::map<date, double>	&getData() const;

	private:
		std::map<date, double>	_data;

		bool 		dateStringToDate(std::string dateString, date &dateStruct);
		std::string	elimWhitespaces(const std::string &string);
		bool		isValidDate(const date &currDate);
		bool		isLeapYear(unsigned int year);
		bool		isValidAmount(std::string amountString, float &currAmount);
		void		showActualValue(const std::string &dateString, const date &currDate, const float &currAmount);
};

#endif /* ************************************************* BITCOINEXCHANGE_H */