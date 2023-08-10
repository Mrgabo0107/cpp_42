#include "ScalarConverter.hpp"

// /*
// ** ------------------------------- CONSTRUCTOR --------------------------------
// */

// ScalarConverter::ScalarConverter()
// {
// }

// ScalarConverter::ScalarConverter( const ScalarConverter & src )
// {
// }


// /*
// ** -------------------------------- DESTRUCTOR --------------------------------
// */

// ScalarConverter::~ScalarConverter()
// {
// }


// /*
// ** --------------------------------- ASSIGN ----------------------------------
// */

// ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/
void	ScalarConverter::convert(const std::string &input)
{
	ScalarConverter::setInput(input);
	ScalarConverter::setType();
	ScalarConverter::setMainValue();
	ScalarConverter::castAnotherValues();
}

bool ScalarConverter::isChar(const std::string &input)
{}

bool ScalarConverter::isInt(const std::string &input)
{}

bool ScalarConverter::isFloat(const std::string &input)
{}

bool ScalarConverter::isDouble(const std::string &input)
{}

bool ScalarConverter::isFloatExtreme(const std::string &input)
{}

bool ScalarConverter::isDoubleExtreme(const std::string &input)
{}

void ScalarConverter::setMainValue(void)
{
	if (_type == CHAR)
		ScalarConverter::setFirstChar();
	else if (_type == INT)
		ScalarConverter::setFirstInt();
	else if (_type == FLOAT)
		ScalarConverter::setFirstFloat();
	else if (_type == DOUBLE)
		ScalarConverter::setFirstDouble();
	else if (_type == F_EXTREME)
		ScalarConverter::setFirstFloatExtreme();
	else if (_type == D_EXTREME)
		ScalarConverter::setFirstDoubleExtreme();
}

std::string	ScalarConverter::doubleExtrFromFloatExtr(void)
{

}

std::string	ScalarConverter::floatExtrFromDoubleExtr(void)
{

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	ScalarConverter::setInput(const std::string &input)
{
	_input = input;
}

void	ScalarConverter::setType(void)
{
	if (ScalarConverter::isChar(_input))
		_type = CHAR;
	else if (ScalarConverter::isInt(_input))
		_type = INT;
	else if (ScalarConverter::isFloat(_input))
		_type = FLOAT;
	else if (ScalarConverter::isDouble(_input))
		_type = DOUBLE;
	else if (ScalarConverter::isFloatExtreme(_input))
		_type = F_EXTREME;
	else if (ScalarConverter::isDoubleExtreme(_input))
		_type = D_EXTREME;
	else
	{
		throw std::invalid_argument("Literal has to be a valid char, int, float or double");
	}
}

void	ScalarConverter::setFirstChar(void)
{}

void	ScalarConverter::setFirstInt(void)
{}

void	ScalarConverter::setFirstFloat(void)
{}

void	ScalarConverter::setFirstDouble(void)
{}

void	ScalarConverter::setFirstFloatExtreme(void)
{}

void	ScalarConverter::setFirstDoubleExtreme(void)
{}

void ScalarConverter::castAnotherValues(void)
{
	if (_type == CHAR)
	{
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
		_floatExtreme = "";
		_doubleExtreme = "";
	}
	else if (_type == INT)
	{
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
		_floatExtreme = "";
		_doubleExtreme = "";
	}
	else if (_type == FLOAT)
	{
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
		_floatExtreme = "";
		_doubleExtreme = "";
	}
	else if (_type == DOUBLE)
	{
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
		_floatExtreme = "";
		_doubleExtreme = "";
	}
	else if (_type == F_EXTREME)
	{
		_char = '\0';
		_int = 0;
		_float = 0.0f;
		_double = 0.0;
		_doubleExtreme = doubleExtrFromFloatExtr();
	}
	else if (_type == D_EXTREME)
	{
		_char = '\0';
		_int = 0;
		_float = 0.0f;
		_double = 0.0;
		_floatExtreme = floatExtrFromDoubleExtr();
	}
}


/*
** --------------------------------- STREAM ---------------------------------
*/
std::ostream &operator<<(std::ostream &o, ScalarConverter const &i)
{
	if (i)
	return o;
}

/* ************************************************************************** */