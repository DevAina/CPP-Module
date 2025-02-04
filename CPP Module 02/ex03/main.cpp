/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:36:19 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/22 10:57:15 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int	main()
{
	Point a( 0, 5.0f);
	Point b( 0, 5.0f);
	Point c(0, 0);
	Point x(0.0f, 0.0f);

	std::cout << bsp(a, b, c, x) << std::endl;
}
