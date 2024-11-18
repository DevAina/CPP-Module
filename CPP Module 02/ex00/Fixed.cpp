/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:32:23 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/18 17:05:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): value(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other): value(other.value) {}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		value = other.value;
	return (*this);
}

int	Fixed::getRawBits()
{
	return (value);
}

void	Fixed::setRawBits(const int raw)
{
	value = raw;
}
