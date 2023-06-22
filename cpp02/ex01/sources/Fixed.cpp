/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:46:30 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 17:27:58 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
: _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
: _rawBits(i << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
: _rawBits(roundf(f * (1 << _fracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator =(const Fixed& fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &fixed)
		this->_rawBits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fracBits));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fracBits);
}

std::ostream& operator <<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}