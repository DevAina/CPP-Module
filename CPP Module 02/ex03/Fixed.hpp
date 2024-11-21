/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:04:37 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/21 09:33:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
class	Fixed
{
	private:
		int	value;
		static const int rawBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed & other);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);
		int		getRawBits(void) const ;
		void	setRawBits(int const raw);
		Fixed	&operator=(const Fixed& other);
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed	min(Fixed &a, Fixed &b);
		static Fixed	min(const Fixed &a, const Fixed &b);
		static Fixed	max(Fixed &a, Fixed &b);
		static Fixed	max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed& other);


#endif
