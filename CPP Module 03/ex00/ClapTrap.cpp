/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:18:24 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 15:15:24 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("Inconnu"), hitPoints(10), EnergyPoints(10), AttackDammage(0)
{
	std::cout << "ClapTrap " << name << " created (Default)\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " created (Constructor copy)\n";
}

ClapTrap::ClapTrap(std::string& nm): name(nm), hitPoints(10), EnergyPoints(10), AttackDammage(0)
{
	std::cout << "ClapTrap " << name << " created.\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignement call\n";
	if (this != &other)
	{
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
	if (hitPoints != 0)
	{
		hitPoints -= amount;
		std::cout << "Takes " << amount << " damage!\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints != 0 && EnergyPoints != 0)
	{
		EnergyPoints--;
		hitPoints += amount;
		std::cout << "Repaired by " << amount << " points!\n";
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor ClapTrap " << name << " call\n";
}

std::string	ClapTrap::getName(void) const
{
	return (name);
}

int		ClapTrap::getHitPoints(void) const
{
	return (hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (EnergyPoints);
}

int	ClapTrap::getAttackDammage(void) const
{
	return (AttackDammage);
}

void	ClapTrap::setName(std::string nm)
{
	name = nm;
}

void	ClapTrap::setHitPoijnts(int hp)
{
	hitPoints = hp;
}

void	ClapTrap::setEnergyPoints(int ep)
{
	EnergyPoints = ep;
}

void	ClapTrap::setAttackDammage(int ad)
{
	AttackDammage = ad;
}
