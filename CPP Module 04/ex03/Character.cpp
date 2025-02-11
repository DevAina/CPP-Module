/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:59 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 14:34:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <cstring>
#include <string>

Character::Character(void): ICharcter(), name()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &nm): ICharcter(), name(nm)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i].clone();
		else
			inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character	&Character::operator=(const other &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i].clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		inventory[idx] = NULL;
}

void	Character::use(int idx, Character& target) const
{
	if (idx >=0 && idx <=3 && inventory[idx])
		inventory[idx].use(target);
}
