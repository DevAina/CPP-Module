/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:34:46 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 13:35:08 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	type = "cure";
}

Cure::Cure(const Cure& other): AMateria(other)
{
	type = other.type;
}

Cure::~Cure(void)
{

}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Cure::use(ICharacter &target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}

Cure	*Cure::clone(void) const
{
	return (new Cure(*this));
}
