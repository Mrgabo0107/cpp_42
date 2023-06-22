/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:39:21 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 23:41:26 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "../includes/Fixed.hpp"

class Point
{
	public:
		//Constructors
		Point();
		Point(const Point& point);
		Point(const float fl1, const float fl2);
		
		//Assignement operator
		Point& operator =(const Point &point);
			
		//Destructor
		~Point();

		//Getters
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		
		//bsp helpers
		Point	operator-(const Point &p1) const;
		Fixed	det(const Point &p1) const;

	private:
		Fixed   _x;
		Fixed   _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif