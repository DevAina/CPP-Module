/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:51:30 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 09:25:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <ostream>

AMateria::AMateria(void): type("Incognito") {}

AMateria::AMateria(const std::string& tp): type(tp) {}

AMateria::AMateria(const AMateria& other)
{
	type = other.type;
}

AMateria::~AMateria(void)
{

}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

std::string	AMateria::getType(void) const
{
	return (type);
}

void	AMateria::use(ICharacter &target) const
{
	std::cout << "****** " << target.getName() <<std::endl;
}
