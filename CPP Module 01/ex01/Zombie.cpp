/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:28 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 09:54:34 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): name("Inconnu") {}

Zombie::~Zombie(void)
{
	std::cout << "\033[1;31m";
	std::cout << "║     A zombie named " << name << " is dead!           ║\n";
	std::cout << "\033[0m";
}

void	Zombie::setName(std::string& nm)
{
	std::string tmp;

	name = nm;
	tmp = name;
	if (name.length() >= 5)
		tmp = name.substr(0, 3) + ".";
	std::cout << "\033[1;33m";
	std::cout << "╔════════════════════════════════════════════════╗\n";
	std::cout << "║                                                ║\n";
	std::cout << "║     A new zombie named " << tmp << " has risen!          ║\n";
	std::cout << "║                                                ║\n";
	std::cout << "╚════════════════════════════════════════════════╝\n";
	std::cout << "\033[0m";
}

void    Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) const
{
	return (name);
}
