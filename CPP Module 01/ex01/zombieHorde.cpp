/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:49 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 09:51:25 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0)
		return (NULL);
	Zombie	*zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}
