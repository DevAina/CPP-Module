/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:09:50 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/20 21:11:14 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed( void ): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	value = nb << rawBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	value = static_cast<int>(roundf(nb * pow(2, rawBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "Comparator operator < called" << std::endl;
	return (value < other.value);
}

bool	Fixed::operator>( const Fixed& other ) const
{
	std::cout << "Comparator operator > called" << std::endl;
	return (value > other.value);
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	std::cout << "Comparator operator >= called" << std::endl;
	return (value >= other.value);
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	std::cout << "Comparator operator <= called" << std::endl;
	return (value <= other.value);
}

bool	Fixed::operator==( const Fixed& other ) const
{
	std::cout << "Comparator operator == called" << std::endl;
	return (value == other.value);
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	std::cout << "Comparator operator != called" << std::endl;
	return (value != other.value);
}

/*surcharge arithmetic operator*/

Fixed	Fixed::operator+(const Fixed& other) const
{
	std::cout << "Arithmetic operator + called";
	return (this->value + other.value);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	std::cout << "Arithmetic operator - called";
	return (this->value - other.value);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	std::cout << "Arithmetic operator * called";
	return ((this->value * other.value) >> rawBits);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	std::cout << "Arithmetic operator / called";
	return ((this->value << rawBits) /  other.value);
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
