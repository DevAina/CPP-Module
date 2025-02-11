/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:25:44 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 13:34:38 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice"), type("ice") 
{

}

Ice::Ice(const Ice& other)
{
	type = other.type;
}

Ice::~Ice(void)
{

}

Ice	Ice::&operator=(const Ice &other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Ice::use(ICharacter &target) const
{
	std::cout << "* shoots an ice bolt at" << target.getName() << " *"<<<<std::endl;
}

void	Ice::clone(void) const
{
	return (new Ice(*this));
}
