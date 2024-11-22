/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/21 15:38:49 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(float const x, float const y): _x(x), _y(y) {}

Point::Point(const Point &point)
{
	_x = point._x;
	_y = point._y;
}

Point	&Point::operator=(const Point &other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}

Point::~Point() {}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}

void	Point::setX(Fixed &newx)
{
	_x = newx;
}

void	Point::setY(Fixed &newy)
{
	_y = newy;
}
