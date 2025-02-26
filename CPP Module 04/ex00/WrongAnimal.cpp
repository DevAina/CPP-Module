/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:48 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/26 16:23:50 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type()
{
	std::cout << WRONGGREEN << "WrongAnimal: Default constructor call\n" << WRONGRESET;
}

WrongAnimal::WrongAnimal(std::string tp): type(tp)
{
	std::cout << WRONGGREEN << "WrongAnimal " << type << " created\n" << WRONGRESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << WRONGGREEN << "WrongAnimal (constructor copy call)\n" << WRONGRESET;
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << WRONGGREEN << "WrongAnimal " << type << " destroyed\n" << WRONGRESET;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << WRONGGREEN << "WrongAnimal: copy assignement call\n" << WRONGRESET;
	if (this != &other)
		type = other.type;
	return (*this);
}

void WrongAnimal::setType(std::string &tp)
{
	type = tp;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << WRONGGREEN << "Sound WrongAnimal.............\n" << WRONGRESET;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
