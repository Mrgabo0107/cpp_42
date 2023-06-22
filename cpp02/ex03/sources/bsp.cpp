/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:50:52 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 23:39:54 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Fixed.hpp"
# include "../includes/Point.hpp"


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed zero(0);
	
	if((c - a).det(point - a) * (b - a).det(point - a) >= zero)
		return (false);
	else if((c - b).det(point - b) * (a - b).det(point - b) >= zero)
		return (false);
	else if((a - c).det(point - c) * (b - c).det(point - c) >= zero)
		return (false);
	return (true);
}