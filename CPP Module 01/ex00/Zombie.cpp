/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:07:50 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/23 14:39:30 by trarijam         ###   ########.fr       */
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

std::string	Zombie::getName(void) const
{
	return (name);
}

void    Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
