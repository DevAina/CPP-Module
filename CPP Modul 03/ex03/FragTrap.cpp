/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:11:54 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/06 07:16:12 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "Default constructor call\n";
	name = "Inconnu";
	hitPoints = 100;
	EnergyPoints = 100;
	AttackDammage = 30;
}

FragTrap::FragTrap(std::string& nm): ClapTrap(nm)
{
	hitPoints = 100;
	EnergyPoints = 100;
	AttackDammage = 30;
	std::cout << "FragTrap " << name << " created\n";
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDammage = other.AttackDammage;
	std::cout << "FragTrap " << name << " created";
	std::cout << "(Constructor copy call)\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << name << " assigned";
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (EnergyPoints != 0 && hitPoints != 0)
	{
		EnergyPoints--;
		std::cout << "FragTrap " << name << " attack " << target
				<< ", causing " << AttackDammage << " points of damage!\n";
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	std::cout << "FragTrap " << name << " takes " << amount << " damage!\n";
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (hitPoints != 0 && EnergyPoints != 0)
	{
		EnergyPoints--;
		hitPoints += amount;
		std::cout << "FragTrap " << name << " is repaired by " << amount << " points!\n";
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five!\n";
}
