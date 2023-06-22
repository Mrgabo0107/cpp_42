/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:51:10 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 23:08:08 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		//Constructors
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& fixed);

		//Assignement operator
		Fixed&	operator =(const Fixed &fixed);
		
		//Destructor
		~Fixed();
		
		//Getters
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
		
		//Setter
		void	setRawBits(const int raw);
		
		//Comparison operators
		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		//Aritmetic operators
		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;

		//Increment and decrement
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		//Min and Max
		static Fixed&		min(Fixed &fixed1, Fixed &fixed2);
		const static Fixed&	min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed&		max(Fixed &fixed1, Fixed &fixed2);
		const static Fixed&	max(const Fixed &fixed1, const Fixed &fixed2);
		
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
};

std::ostream& operator <<(std::ostream& o, const Fixed& fixed);

#endif