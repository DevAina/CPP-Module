/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtfa <trarijam@student.42antananarivo.mg>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:40:07 by rtfa              #+#    #+#             */
/*   Updated: 2025/02/04 18:02:27 by rtfa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("Inconnu"), hitPoints(10), EnergyPoints(10), AttackDammage(0)
{
	std::cout << "ClapTrap " << name << " created (Default)\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDammage = other.AttackDammage;
	std::cout << "ClapTrap " << name << " created (Constructor copy)\n";
}

ClapTrap::ClapTrap(std::string& nm): name(nm), hitPoints(10), EnergyPoints(10), AttackDammage(0)
{
	std::cout << "ClapTrap " << name << " created.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignement call\n";
		name = other.name;
		hitPoints = other.EnergyPoints;
		AttackDammage = other.AttackDammage;
		EnergyPoints = other.EnergyPoints;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (EnergyPoints != 0 && hitPoints != 0)
	{
		EnergyPoints--;
		std::cout << "ClapTrap " << name << " attack " << target
				<< ", causing " << AttackDammage << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints != 0 && EnergyPoints != 0)
	{
		EnergyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << "is repaired by " << amount << " points!\n";
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor ClapTrap " << name << " call\n";
}
