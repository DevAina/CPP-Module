/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:36:53 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 08:58:23 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

#include <iostream>
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
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed& other);

#endif
