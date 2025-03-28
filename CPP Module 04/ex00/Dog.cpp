/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:11:16 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 11:41:04 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	type = "Dog";
	std::cout << YELLOW << "Dog(Constructor default)\n" << RESET;
}

Dog::Dog(const Dog &other): Animal(other)
{
	std::cout << YELLOW << "Dog(constructor copy call)\n" << RESET;
	type = other.type;
}

Dog::~Dog(void)
{
	std::cout << YELLOW << "Dog destroyed\n" << RESET;
}

Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << "Woaf.....!\n" << RESET;
}
