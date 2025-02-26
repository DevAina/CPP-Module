/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:32:52 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 15:45:03 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "Scavtrap Default constructor call\n";
	name = "Inconnu";
	hitPoints = 100;
	EnergyPoints = 50;
	AttackDammage = 20;
}

ScavTrap::ScavTrap(std::string& nm): ClapTrap(nm)
{
	hitPoints = 100;
	EnergyPoints = 50;
	AttackDammage = 20;
	std::cout << "ScavTrap " << name << " created\n";
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << name << " created";
	std::cout << "(Constructor copy call)\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDammage = other.AttackDammage;
	}
	std::cout << "ScavTrap " << name << " assigned";
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (EnergyPoints != 0 && hitPoints != 0)
	{
		EnergyPoints--;
		std::cout << "ScavTrap " << name << " attack " << target
				<< ", causing " << AttackDammage << " points of damage!\n";
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}
