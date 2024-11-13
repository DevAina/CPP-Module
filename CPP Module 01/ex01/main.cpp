/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:30 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/13 13:16:48 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
# include <string>

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