/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:57:51 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/12 04:54:43 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define IMP "Impossible"
# define N_D "Non diplayable"

# include <iostream>
# include <sstream>
# include <string>
# include <limits>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	F_EXTREME,
	D_EXTREME
};

enum e_message 
{
	IMPOSS,
	N_DSPL,
	GOOD
};

class ScalarConverter
{

	public:
		// ScalarConverter();
		// ScalarConverter(ScalarConverter const &src);
		// ~ScalarConverter();
		// ScalarConverter &operator=(ScalarConverter const &rhs);
		
		static void	convert(const std::string &input);
	
	private:
		//Attributs
		static std::string	_input;
		static e_type		_type;
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;

		//Accessors
		static void					setInput(const std::string &input);
		
		static void					setType(void);
		static bool					isChar(void);
		static bool					isInt(void);
		static bool					isFloat(void);
		static bool					isDouble(void);
		static bool					isFloatExtreme(void);
		static bool					isDoubleExtreme(void);
		
		//Methods
		static void 				AnotherValues(void);
		static void					solveChar(void);
		static void 				solveInt(void);
		static void 				solveFloat(void);
		static void 				solveDouble(void);
		static void 				solveFExtreme(void);
		static void 				solveDExtreme(void);
		static void					intFromChar(void);
		static void					floatFromChar(void);
		static void					doubleFromChar(void);
		static e_message			charFromInt(void);
		static void					floatFromInt(void);
		static void					doubleFromInt(void);
		static e_message			intFromFloat(void);
		static void					doubleFromFloat(void);
		static e_message			floatFromDouble(void);
};

#endif /* ************************************************* SCALARCONVERTER_H */