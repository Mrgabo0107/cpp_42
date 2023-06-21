/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:51:10 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/21 19:26:26 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed(const Fixed& fixed);
		Fixed&	operator=(const Fixed &fixed );
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
};

#endif