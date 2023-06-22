/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:39:16 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/22 23:41:34 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Fixed.hpp"
# include "../includes/Point.hpp"

//Constructors
Point::Point()
:_x(0), _y(0)
{
}

Point::Point(const Point& point)
{
    *this = point;
}

Point::Point(const float fl1, const float fl2)
:_x(fl1), _y(fl2)
{
}

//Assignement operator
Point&  Point::operator =(const Point &point)
{
    if (this != &point)
	{
		this->_x = point.getX();
		this->_y = point.getY();
	}
	return *this;
}

//Destructor
Point::~Point()
{
}

//Getters
Fixed	Point::getX(void) const
{
    return (this->_x);
}

Fixed	Point::getY(void) const
{
    return (this->_y);
}

//bsp helpers
Point	Point::operator-(const Point &p1) const
{
	return(Point((this->_x - p1._x).toFloat(), (this->_y - p1._y).toFloat()));
}

Fixed	Point::det(const Point &p1) const
{
	return ((this->_x * p1._y) - (this->_y * p1._x));
}