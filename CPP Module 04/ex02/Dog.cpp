/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:11:16 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 18:18:28 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << YELLOW << "Dog(Constructor default)\n" << RESET;
}

Dog::Dog(const Dog &other): Animal(other), brain(NULL)
{
	std::cout << YELLOW << "Dog(constructor copy call)\n" << RESET;
	*this = other;
}

Dog::~Dog(void)
{
	if (brain)
		delete brain;
	std::cout << YELLOW << "Dog destroyed\n" << RESET;
}

Dog &Dog::operator=(const Dog& other)
{
	std::cout << YELLOW << "Assignment call\n" << RESET;
	if (this != &other)
	{
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
	return (*this);
}


void	Dog::makeSound(void)
{
	std::cout << YELLOW << "Woaf.....!\n" << RESET;
}
