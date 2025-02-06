/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:32:52 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/04 20:00:54 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "Default constructor call\n";
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
	name = other.name;
	hitPoints = other.hitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDammage = other.AttackDammage;
	std::cout << "ScavTrap " << name << " created";
	std::cout << "(Constructor copy call)\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	std::cout << "ScavTrap " << name << " takes " << amount << " damage!\n";
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints != 0 && EnergyPoints != 0)
	{
		EnergyPoints--;
		hitPoints += amount;
		std::cout << "ScavTrap " << name << " is repaired by " << amount << " points!\n";
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!\n";
}
