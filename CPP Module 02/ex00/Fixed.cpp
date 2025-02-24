/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:32:23 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 14:48:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iterator>
#include <ostream>

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
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

int	Fixed::getRawBits()
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void	Fixed::setRawBits(const int raw)
{
	value = raw;
}
