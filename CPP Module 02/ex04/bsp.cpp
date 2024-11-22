/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:00:48 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/22 10:54:11 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Point.hpp"

Fixed sign(Point const & p1, Point const & p2, Point const & p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - 
           (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return (!(has_neg && has_pos) && 
           d1 != 0 && d2 != 0 && d3 != 0);
}