/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:54:40 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/20 10:30:44 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>

class	Fixed
{
	private:
		int	value;
		static const int	rawBits = 8;
	
	public:
		Fixed(void);
		Fixed(const int nb);
		Fixed(const float nb_float);
		Fixed(const Fixed& other);
		~Fixed(void);
		int		getRawBits();
		void	setRawBits(int const raw);
		Fixed	&operator=(const Fixed& other);
		friend std::ostream	&operator<<(std::ostream &os, const Fixed& other);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif
