/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:51:10 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 22:04:45 by gamoreno         ###   ########.fr       */
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

		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& fixed);
		Fixed&	operator=(const Fixed &fixed );
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
};

std::ostream& operator <<(std::ostream& o, const Fixed& fixed);

#endif