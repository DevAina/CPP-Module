/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:43:45 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/20 11:18:03 by trarijam         ###   ########.fr       */
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
	value = nb * pow(2, rawBits);
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
	return (value / pow(2, rawBits));
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
