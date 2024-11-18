/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:37:08 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/18 17:05:54 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int	value;
		static const int	rawBits = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		~Fixed(void);
		int		getRawBits();
		void	setRawBits(int const raw);
		Fixed	&operator=(const Fixed& other);
};

#endif
