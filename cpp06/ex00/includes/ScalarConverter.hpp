/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:57:51 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/10 16:59:34 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	F_EXTREME,
	D_EXTREME
};

class ScalarConverter
{

	public:
		// ScalarConverter();
		// ScalarConverter( ScalarConverter const & src );
		// ~ScalarConverter();
		// ScalarConverter &		operator=( ScalarConverter const & rhs );
		
		static void	convert(const std::string &input);
	
	private:
		//Attributs
		static std::string	_input;
		static e_type		_type;
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;
		static std::string	_floatExtreme;
		static std::string	_doubleExtreme;

		//Accessors
		static void					setInput(const std::string &input);
		static void					setType(void);
		static void					setFirstChar(void);
		static void					setFirstInt(void);
		static void					setFirstFloat(void);
		static void					setFirstDouble(void);
		static void					setFirstFloatExtreme(void);
		static void					setFirstDoubleExtreme(void);
		static void 				castAnotherValues(void);
		static const e_type			&getType();
		static const char			&getChar();
		static const int			&getInt();
		static const float			&getFloat();
		static const double			&getDouble();
		static const std::string	&getFloatExtreme();
		static const std::string	&getDoubleExtrme();

		//Methods
		static bool 		isChar(const std::string &input);
		static bool 		isInt(const std::string &input);
		static bool 		isFloat(const std::string &input);
		static bool 		isDouble(const std::string &input);
		static bool 		isFloatExtreme(const std::string &input);
		static bool 		isDoubleExtreme(const std::string &input);
		static void 		setMainValue(void);
		static std::string	doubleExtrFromFloatExtr(void);
		static std::string	floatExtrFromDoubleExtr(void);
};

std::ostream &operator<<(std::ostream &o, ScalarConverter const &i);

#endif /* ************************************************* SCALARCONVERTER_H */