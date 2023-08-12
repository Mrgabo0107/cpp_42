#include "ScalarConverter.hpp"

// /*
// ** ------------------------------- CONSTRUCTOR --------------------------------
// */

// ScalarConverter::ScalarConverter()
// {}

// ScalarConverter::ScalarConverter(const ScalarConverter &src)
// {
//		*this = src
// }

// /*
// ** -------------------------------- DESTRUCTOR --------------------------------
// */

// ScalarConverter::~ScalarConverter()
// {}

// /*
// ** --------------------------------- ASSIGN ----------------------------------
// */

// ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
// {
// 	(void)rhc;
// 	return *this;
// }

std::string	ScalarConverter::_input;
e_type		ScalarConverter::_type;
char		ScalarConverter::_char;
int			ScalarConverter::_int;
float		ScalarConverter::_float;
double		ScalarConverter::_double;

/*
** --------------------------------- METHODS ----------------------------------
*/
void ScalarConverter::convert(const std::string &input)
{
	ScalarConverter::setInput(input);
	ScalarConverter::setType();
	ScalarConverter::AnotherValues();
	std::cout << "type " <<_type << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
void ScalarConverter::setInput(const std::string &input)
{
	_input = input;
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
	if (_input.find_first_not_of("-+0123456789") != std::string::npos \
	|| (_input.find_last_of("+-") != 0 && _input.find_last_of("+-") != std::string::npos))
		return false;
	long int aux;
	std::istringstream iss(_input);
	iss >> aux;
	if (iss.fail())
		return false;
	if (aux < std::numeric_limits<int>::min() || aux > std::numeric_limits<int>::max())
		return false;
	iss.clear();
    iss.seekg(0);
	iss >> _int;
	if (iss.fail())
		return false;
	return true;
}

bool ScalarConverter::isFloat(void)
{
	if (_input.find_first_not_of("-+0123456789.f") != std::string::npos \
	|| (_input.find_last_of("+-") != 0 && _input.find_last_of("+-") != std::string::npos) \
	|| _input.find_first_of("f") != _input.length() - 1)
		return false;
	double aux;
	std::istringstream iss(_input);
	iss >> aux;
	std::cout << "double taken " <<  std::numeric_limits<float>::min() << aux << std::endl;
	if (iss.fail())
		return false;
	if (aux < std::numeric_limits<float>::min() || aux > std::numeric_limits<float>::max())
		return false;
	iss.clear();
    iss.seekg(0);
	iss >> _float;
	if (iss.fail())
		return false;
	return true;
}

bool ScalarConverter::isDouble(void)
{
	std::istringstream iss(_input);
	iss >> _double;
	if (iss.fail())
		return false;
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
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
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
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
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
		if (ScalarConverter::charFromInt() == IMPOSS)  
			std::cout << "char: " << IMP << std::endl;
		else if (ScalarConverter::charFromInt() == N_DSPL)
			std::cout << "char: " << N_D << std::endl;
		else if (ScalarConverter::charFromInt() == GOOD)
			std::cout << "char: \'" << _char  << "\'"<< std::endl;
		std::cout << "int: " << _int << std::endl;
	}
	std::cout << "float: " << _float << std::endl;
	std::cout << "double: " << _double << std::endl;
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
		if (ScalarConverter::intFromFloat() == IMPOSS)
		{
			std::cout << "char: " << IMP << std::endl;
			std::cout << "int: " << IMP << std::endl;
			std::cout << "float: " << _float << std::endl;
		}
		else if (ScalarConverter::intFromFloat() == GOOD)
		{
			if (ScalarConverter::charFromInt() == IMPOSS)  
				std::cout << "char: " << IMP << std::endl;
			else if (ScalarConverter::charFromInt() == N_DSPL)
				std::cout << "char: " << N_D << std::endl;
			else if (ScalarConverter::charFromInt() == GOOD)
				std::cout << "char: \'" << _char  << "\'"<< std::endl;
			std::cout << "int: " << _int << std::endl;
			std::cout << "float: " << _float << std::endl;
		}
	}
	std::cout << "double: " << _double << std::endl;
}

void ScalarConverter::solveFExtreme(void)
{
	std::cout << "char: " << IMP << std::endl;
	std::cout << "int: " << IMP << std::endl;
	std::cout << "float: " << _input << std::endl;
	double extr;
	if (_input == "-inff")
	{
		extr = static_cast<double>(std::numeric_limits<float>::min());
		std::cout << "double: " << extr << std::endl;
	}
	else if (_input == "+inff")
	{
		extr = static_cast<double>(std::numeric_limits<float>::max());
		std::cout << "double: " << extr << std::endl;
	}
	else if (_input == "nanf")
		std::cout << "double: nan" << std::endl;
}

void ScalarConverter::solveDExtreme(void)
{
	std::cout << "char: " << IMP << std::endl;
	std::cout << "int: " << IMP << std::endl;
	if (_input == "nan")
	{
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: " << _input << std::endl;
	}
	else
	{
	std::cout << "float: " << IMP << std::endl;
	std::cout << "double: " << _input << std::endl;
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
e_message ScalarConverter::intFromFloat(void)
{
	if (static_cast<long int>(_float) < static_cast<long int>(std::numeric_limits<int>::min()) \
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
e_message ScalarConverter::floatFromDouble(void)
{
	if (_double < static_cast<double>(std::numeric_limits<float>::min()) \
	|| _double > static_cast<double>(std::numeric_limits<float >::max()))
		return (IMPOSS);
	_float = static_cast<float>(_double);
	return (GOOD);
}

/* ************************************************************************** */