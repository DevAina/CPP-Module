/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:40:23 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 13:51:06 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type()
{
	std::cout << GREEN << "Animal: Default constructor call\n" << RESET;
}

Animal::Animal(std::string &tp): type(tp)
{
	std::cout << GREEN << "Animal " << type << " created\n" << RESET;
}

Animal::Animal(const Animal& other)
{
	std::cout << GREEN << "Animal (constructor copy call)\n" << RESET;
	type = other.type;
}

Animal::~Animal(void)
{
	std::cout << GREEN << "Animal " << type << " destroyed\n" << RESET;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		std::cout << GREEN << "Animal: copy assignement call\n" << RESET;
		type = other.type;
	}
	return (*this);
}

void Animal::setType(std::string &tp)
{
	type = tp;
}

std::string	Animal::getType(void) const
{
	return (type);
}
