/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:28:47 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/06 16:27:27 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <ostream>

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap(), name("Incognito")
{
	hitPoints = FragTrap::hitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDammage = FragTrap::AttackDammage;
	std::cout << "DiamondTrap Constructor default call"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string &nm): ClapTrap(nm.append("_clap_name")), ScavTrap(nm), FragTrap(nm), name(nm)
{
	hitPoints = FragTrap::hitPoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDammage = FragTrap::AttackDammage;
	std::cout << "DiamondTrap " << name << " created\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ScavTrap(other), FragTrap(other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDammage = other.AttackDammage;
	std::cout << "DiamondTrap " << name << " created";
	std::cout << "(Constructor copy call)\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << name << " destroyed\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignement call(DiamondTrap)"<< std::endl;
		name = other.name;
		hitPoints = other.hitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDammage = other.AttackDammage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;	
}
