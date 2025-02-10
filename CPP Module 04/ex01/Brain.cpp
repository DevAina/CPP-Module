/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:50:17 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 09:24:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain(Default constructor call)\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain(Constructor copy call)\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}
