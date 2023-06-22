/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:46:30 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 23:08:17 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

//Constructors
Fixed::Fixed()
: _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
: _rawBits(i << _fracBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
: _rawBits(roundf(f * (1 << _fracBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//Assignement operator
Fixed&	Fixed::operator =(const Fixed &fixed)
{
	// std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)
		this->_rawBits = fixed.getRawBits();
	return *this;
}

//Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

//Getters
int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fracBits));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fracBits);
}

//Setter
void	Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

//comparison operators
bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_rawBits > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_rawBits < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_rawBits >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_rawBits <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_rawBits == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_rawBits != fixed.getRawBits());
}

//Aritmetic operators
Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return(Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return(Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return(Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return(Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed&	Fixed::operator++()
{
	this->_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--()
{
	this->_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);

	operator--();
	return tmp;
}

//Min and Max
Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed&	Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed&	Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

std::ostream& operator <<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}
