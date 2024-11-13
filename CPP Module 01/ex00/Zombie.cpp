/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:20:53 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/13 11:41:25 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name)
{
	if (name.length() >= 3)
		name = name.substr(0, 3) + ".";
    std::cout << "\033[1;33m";
	std::cout << "╔══════════════════════════════════════════╗\n";
	std::cout << "║                                          ║\n";
	std::cout << "║  A new zombie named " << name << " has risen!      ║\n";
	std::cout << "║                                          ║\n";
	std::cout << "╚══════════════════════════════════════════╝\n";
	std::cout << "\033[0m";
}

Zombie::~Zombie() 
{
	if (name.length() >= 3)
		name = name.substr(0, 3) + ".";
	std::cout << "\033[1;31m";
	std::cout << "╔══════════════════════════════════════════╗\n";
	std::cout << "║                                          ║\n";
	std::cout << "║  A zombie named " << name << " is dead!            ║\n";
	std::cout << "║                                          ║\n";
	std::cout << "╚══════════════════════════════════════════╝\n";
	std::cout << "\033[0m";
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}