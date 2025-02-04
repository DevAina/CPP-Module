/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:53:21 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/21 10:55:21 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed( void ): value(0) {}

Fixed::Fixed(const Fixed &other): value(other.value) {}

Fixed::Fixed(const int nb)
{
	value = nb << rawBits;
}

Fixed::Fixed(const float nb)
{
	value = static_cast<int>(roundf(nb * pow(2, rawBits)));
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits( void ) const
{
	return (rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value / pow(2, rawBits)));
}

int	Fixed::toInt( void ) const
{
	return (value >> rawBits);
}

Fixed	&Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		value = other.value;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

/*Surcharge comparaison operator*/
bool	Fixed::operator<( const Fixed& other ) const
{
	return (value < other.value);
}

bool	Fixed::operator>( const Fixed& other ) const
{
	return (value > other.value);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return (value >= other.value);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return (value <= other.value);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return (value == other.value);
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return (value != other.value);
}

/*surcharge arithmetic operator*/
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.value = value + other.value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.value = value - other.value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result.value = (value * other.value) >> rawBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	if (other.value == 0)
		return (result);
	result.value = (value << rawBits) / other.value;
	return (result);
}

/*++x*/
Fixed	Fixed::operator++()
{
	value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--(*this);
	return (tmp);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (b > a)
		return (b);
	return (a);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (b > a)
		return (b);
	return (a);
}
