/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:30:59 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/13 11:02:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie* newZombie( std::string name );

int	main(void)
{
	Zombie	*Zombie = newZombie("Bob");
	randomChump("Alice");
	Zombie->announce();
	delete Zombie;
	return (0);
}