/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:47 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 11:40:33 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(float const x, float const y): _x(x), _y(y) {}

Point::Point(const Point &point)
{
	static_cast<Fixed>(_x) = point._x;
	static_cast<Fixed>(_y) = point._y;
}

Point	&Point::operator=(const Point &other)
{
	if (this != &other)
	{
		static_cast<Fixed>(_x) = other._x;
		static_cast<Fixed>(_y) = other._y;
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
