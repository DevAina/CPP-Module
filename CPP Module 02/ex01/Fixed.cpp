/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:11:22 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/20 10:30:27 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <ostream>

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const  nb )
{
	std::cout << "Int constructor called" << std::endl;
	value = nb * pow(2, rawBits);
}

Fixed::Fixed( float const nb_float )
{
	std::cout << "Float constructor called" << std::endl;
	value = static_cast<int>(roundf(nb_float * pow(2, rawBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignement operator called" << std::endl;
		value = other.value;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream &os, const Fixed & other)
{
	os << other.toFloat();
	return (os);
}


int	Fixed::getRawBits( void )
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(const int raw)
{
	value = raw;
}

float	Fixed::toFloat( void ) const
{
	float	tofloat =  static_cast<float>(value / pow(2, rawBits));
	return (tofloat);
}

int	Fixed::toInt( void  ) const
{
	int	toint = static_cast<int>(value / pow(2, rawBits));
	return (toint);
}


