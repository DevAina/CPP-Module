/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:19:39 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 11:40:49 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	
	public:
		Point(void);
		Point(float const x, float const y);
		Point(const Point &point);
		Point	&operator=(const Point &other);
		~Point(void);
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

#endif
