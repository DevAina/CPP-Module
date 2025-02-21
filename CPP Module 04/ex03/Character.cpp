/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:59 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/21 19:01:19 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <cstring>
#include <string>

Character::Character(void): ICharacter(), name()
{
	materiasol = NULL;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const std::string &nm): ICharacter(), name(nm)
{
	materiasol = NULL;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other): ICharacter(other)
{
	materiasol = NULL;
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	t_materiasol	*tmp;

	if (materiasol)
	{
		while (materiasol)
		{
			tmp = materiasol;
			materiasol = materiasol->next;
			delete tmp;
		}
	}
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		materiasol = NULL;
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i];
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
	t_materiasol	*temp;

	if (idx >= 0 && idx <= 3)
	{
		temp = new t_materiasol;
		temp->tmp = inventory[idx];
		temp->next = NULL;
		addBack(&materiasol, temp);
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >=0 && idx <=3 && inventory[idx])
		inventory[idx]->use(target);
}
