/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:12:27 by gamoreno          #+#    #+#             */
/*   Updated: 2023/09/06 00:22:46 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string dataPath);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void	executeBitcoinExchange(std::string inputPath);
		
		const std::map<std::string, double>	&getData() const;

	private:
		std::map<std::string, double>	_data;
};

#endif /* ************************************************* BITCOINEXCHANGE_H */