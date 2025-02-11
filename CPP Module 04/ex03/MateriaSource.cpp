/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:21 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 15:19:02 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <cstring>

MateriaSource::MateriaSource(void): IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other): IMateriaSource(other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.learnedMateria[i])
			learnedMateria[i] = other.learnedMateria[i]->clone();
		else
			learnedMateria[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (learnedMateria[i])
				delete learnedMateria[i];
			if (other.learnedMateria[i])
				learnedMateria[i] = other.learnedMateria[i]->clone();
			else
				learnedMateria[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMateria[i])
			delete learnedMateria[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!learnedMateria[i])
		{
			learnedMateria[i] = m->clone();
			break;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMateria[i] && learnedMateria[i]->getType() == type)
			return (learnedMateria[i]->clone());
	}
	return (NULL);
}
