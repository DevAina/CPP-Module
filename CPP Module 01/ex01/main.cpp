/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:22 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:21:02 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name );

int main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
    	Zombie* zombies = zombieHorde(std::stoi(argv[1]), "Bob");
    	delete [] zombies;
	}
    return 0;
}