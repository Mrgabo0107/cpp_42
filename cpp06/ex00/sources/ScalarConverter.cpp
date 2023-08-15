#include "ScalarConverter.hpp"

std::string	ScalarConverter::_input;
e_type		ScalarConverter::_type;
char		ScalarConverter::_char;
int			ScalarConverter::_int;
float		ScalarConverter::_float;
double		ScalarConverter::_double;

/*
** ------------------------------- CONTEXTUAL GARBAGE --------------------------------
*/

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{}


ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void ScalarConverter::convert(const std::string &input)
{
	ScalarConverter::setInput(input);
	ScalarConverter::setType();
	ScalarConverter::AnotherValues();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string ScalarConverter::trim(const std::string& input)
{
	size_t start = input.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = input.find_last_not_of(" \t\r\n");
	return input.substr(start, end - start + 1);
}

void ScalarConverter::setInput(const std::string &input)
{
	_input = trim(input);
}

void ScalarConverter::setType(void)
{
	if (ScalarConverter::isChar())
		_type = CHAR;
	else if (ScalarConverter::isInt())
		_type = INT;
	else if (ScalarConverter::isFloat())
		_type = FLOAT;
	else if (ScalarConverter::isDouble())
		_type = DOUBLE;
	else if (ScalarConverter::isFloatExtreme())
		_type = F_EXTREME;
	else if (ScalarConverter::isDoubleExtreme())
		_type = D_EXTREME;
	else
	{
		throw std::invalid_argument("Literal has to be a valid char, int, float or double");
	}
}


bool ScalarConverter::isChar(void)
{
	if (_input.length() == 1 && std::isalpha(_input[0]) && std::isprint(_input[0]))
	{
		_char = _input[0];
		return true;
	}
	return false;
}

bool ScalarConverter::isInt(void)
{
	char *endptr;
	long int aux = strtol(_input.c_str(), &endptr, 10);	
	
	if (*endptr != '\0')
		return false;
	if (aux < std::numeric_limits<int>::min() || aux > std::numeric_limits<int>::max())
		return false;
	_int = static_cast<int>(aux);
	return true;
}

bool ScalarConverter::isFloat(void)
{
	if (_input.find('f') != _input.length() - 1)
		return false;
	std::string subinput = _input.substr(0, _input.length() - 1);
	char *endptr;
	float aux = strtof(subinput.c_str(), &endptr);

	if (*endptr != '\0')
		return false;
	if (aux < -std::numeric_limits<float>::max() || aux > std::numeric_limits<float>::max())
		return false;
	_float = aux;
	return true;
}

bool ScalarConverter::isDouble(void)
{
	char* endptr;
	double aux = strtod(_input.c_str(), &endptr);

	if (*endptr != '\0')
        	return false;
	if (aux < -std::numeric_limits<double>::max() || aux > std::numeric_limits<double>::max())
        	return false;
	_double = aux;
	return true;
}

bool ScalarConverter::isFloatExtreme(void)
{
	if (_input == "-inff" || _input == "+inff" || _input == "nanf")
		return (true);
	return (false);
}

bool ScalarConverter::isDoubleExtreme(void)
{
	if (_input == "-inf" || _input == "+inf" || _input == "nan")
		return (true);
	return (false);
}

void ScalarConverter::AnotherValues(void)
{
	if (_type == CHAR)
	{
		ScalarConverter::solveChar();
	}
	else if (_type == INT)
	{
		ScalarConverter::solveInt();
	}
	else if (_type == FLOAT)
	{
		ScalarConverter::solveFloat();
	}
	else if (_type == DOUBLE)
	{
		ScalarConverter::solveDouble();
	}
	else if (_type == F_EXTREME)
	{
		ScalarConverter::solveFExtreme();
	}
	else if (_type == D_EXTREME)
	{
		ScalarConverter::solveDExtreme();
	}
}

void ScalarConverter::solveChar(void)
{
	ScalarConverter::doubleFromChar();
	ScalarConverter::floatFromChar();
	ScalarConverter::intFromChar();
	std::cout << "char: \'" << _char << "\'" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _float << 'f' << std::endl;
	std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
}

void ScalarConverter::solveInt(void)
{
	ScalarConverter::doubleFromInt();
	ScalarConverter::floatFromInt();
	if (ScalarConverter::charFromInt() == IMPOSS)
		std::cout << "char: " << IMP << std::endl;
	else if (ScalarConverter::charFromInt() == N_DSPL)
		std::cout << "char: " << N_D << std::endl;
	else if (ScalarConverter::charFromInt() == GOOD)
		std::cout << "char: \'" << _char << "\'" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _float << 'f' << std::endl;
	std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
}

void ScalarConverter::solveFloat(void)
{
	ScalarConverter::doubleFromFloat();
	if (ScalarConverter::intFromFloat() == IMPOSS)
	{
		std::cout << "char: " << IMP << std::endl;
		std::cout << "int: " << IMP << std::endl;
	}
	else if (ScalarConverter::intFromFloat() == GOOD)
	{
		if (ScalarConverter::charFromFloat() == IMPOSS)  
			std::cout << "char: " << IMP << std::endl;
		else if (ScalarConverter::charFromFloat() == N_DSPL)
			std::cout << "char: " << N_D << std::endl;
		else if (ScalarConverter::charFromFloat() == GOOD)
			std::cout << "char: \'" << _char  << "\'"<< std::endl;
		std::cout << "int: " << _int << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << _float << 'f' << std::endl;
	std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
}

void ScalarConverter::solveDouble(void)
{
	if (ScalarConverter::floatFromDouble() == IMPOSS)
	{
		std::cout << "char: " << IMP << std::endl;
		std::cout << "int: " << IMP << std::endl;
		std::cout << "float: " << IMP << std::endl;
	}
	else if (ScalarConverter::floatFromDouble() == GOOD)
	{
		if (ScalarConverter::intFromDouble() == IMPOSS)
		{
			std::cout << "char: " << IMP << std::endl;
			std::cout << "int: " << IMP << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << _float << 'f' << std::endl;
		}
		else if (ScalarConverter::intFromDouble() == GOOD)
		{
			if (ScalarConverter::charFromDouble() == IMPOSS)  
				std::cout << "char: " << IMP << std::endl;
			else if (ScalarConverter::charFromDouble() == N_DSPL)
				std::cout << "char: " << N_D << std::endl;
			else if (ScalarConverter::charFromDouble() == GOOD)
				std::cout << "char: \'" << _char  << "\'"<< std::endl;
			std::cout << "int: " << _int << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << _float << 'f' << std::endl;
		}
	}
	std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
}

void ScalarConverter::solveFExtreme(void)
{
	std::cout << "char: " << IMP << std::endl;
	std::cout << "int: " << IMP << std::endl;
	if (_input == "-inff")
	{
		_float = -std::numeric_limits<float>::infinity();
		_double = static_cast<double>(_float);
		std::cout << std::fixed << std::setprecision(1) << "float: " << _float << 'f' << std::endl;
		std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
	}
	else if (_input == "+inff")
	{
		_float = std::numeric_limits<float>::infinity();
		_double = static_cast<double>(_float);
		std::cout << std::fixed << std::setprecision(1) << "float: " << _float << 'f' << std::endl;
		std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
	}
}

void ScalarConverter::solveDExtreme(void)
{
	std::cout << "char: " << IMP << std::endl;
	std::cout << "int: " << IMP << std::endl;
	if (_input == "-inf")
	{
		_double = -std::numeric_limits<double>::infinity();
		_float = static_cast<float>(_double);  
		std::cout << std::fixed << std::setprecision(1) << "float: " << _float << 'f' << std::endl;
		std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
	}
	else if (_input == "+inf")
	{
		_double = std::numeric_limits<double>::infinity();
		_float = static_cast<float>(_double);
		std::cout << std::fixed << std::setprecision(1) << "float: " << _float << 'f' << std::endl;
		std::cout << "double: "  << std::fixed << std::setprecision(1) << _double << std::endl;
	}
}

// CHAR
void ScalarConverter::intFromChar(void)
{
	_int = static_cast<int>(_char);
}

void ScalarConverter::floatFromChar(void)
{
	_float = static_cast<float>(_char);
}

void ScalarConverter::doubleFromChar(void)
{
	_double = static_cast<double>(_char);
}

// INT
e_message ScalarConverter::charFromInt(void)
{
	if (_int < 0 || _int > 127)
		return (IMPOSS);
	if (_int < 32 || _int > 126)
		return (N_DSPL);
	_char = static_cast<char>(_int);
	return (GOOD);
}

void ScalarConverter::floatFromInt(void)
{
	_float = static_cast<float>(_int);
}

void ScalarConverter::doubleFromInt(void)
{
	_double = static_cast<double>(_int);
}

// FLOAT
e_message ScalarConverter::charFromFloat(void)
{
	if (_float < 0 || _float > 127)
		return (IMPOSS);
	if (_float < 32 || _float > 126)
		return (N_DSPL);
	_char = static_cast<char>(_float);
	return (GOOD);
}

e_message ScalarConverter::intFromFloat(void)
{
	if (static_cast<long int>(_float) < static_cast<long int>(std::numeric_limits<int>::min())
	|| static_cast<long int>(_float) > static_cast<long int>(std::numeric_limits<int>::max()))
		return (IMPOSS);
	_int = static_cast<int>(_float);
	return (GOOD);
}

void ScalarConverter::doubleFromFloat(void)
{
	_double = static_cast<double>(_float);
}

// DOUBLE
e_message ScalarConverter::charFromDouble(void)
{
	if (_double < 0 || _double > 127)
		return (IMPOSS);
	if (_double < 32 || _double > 126)
		return (N_DSPL);
	_char = static_cast<char>(_double);
	return (GOOD);
}

e_message ScalarConverter::intFromDouble(void)
{
	if (static_cast<long int>(_double) < static_cast<long int>(std::numeric_limits<int>::min())
	|| static_cast<long int>(_double) > static_cast<long int>(std::numeric_limits<int>::max()))
		return (IMPOSS);
	_int = static_cast<int>(_double);
	return (GOOD);
}

e_message ScalarConverter::floatFromDouble(void)
{
	if ((0 < std::abs(_double) && std::abs(_double) < static_cast<double>(std::numeric_limits<float>::min()))
	|| _double < -static_cast<double>(std::numeric_limits<float>::max())
	|| _double > static_cast<double>(std::numeric_limits<float>::max()))
		return (IMPOSS);
	_float = static_cast<float>(_double);
	return (GOOD);
}

/* ************************************************************************** */
