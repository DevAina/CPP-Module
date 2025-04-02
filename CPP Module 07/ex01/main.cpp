/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 07:27:13 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/02 07:37:02 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <string>

void	Multiply2(int& nb)
{
	nb *= 2;
}

int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5, 6, 7};
	size_t	len = sizeof(tab) / sizeof(tab[0]);
	iter(tab, len, Multiply2);
	for (size_t i = 0; i < len; i++)
	{
		std::cout << "[" << tab[i] << "]" << std::endl;
	}
	return (0);
}
