/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 10:52:40 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    Zombie* zombies = zombieHorde(6, "Bob");
    delete [] zombies;
    return 0;
}