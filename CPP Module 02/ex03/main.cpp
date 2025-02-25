/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:36:19 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 09:26:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int	main()
{
	Point a( 0, 0);
	Point b( 0, 5);
	Point c(2.5f, 4);
	Point x(1, 2);

	std::cout << bsp(a, b, c, x) << std::endl;
}
