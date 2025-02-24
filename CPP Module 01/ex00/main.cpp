/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:07:06 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:20:27 by trarijam         ###   ########.fr       */
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
