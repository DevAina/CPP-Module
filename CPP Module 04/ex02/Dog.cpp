/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:11:16 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:41 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << YELLOW << "Dog(Constructor default)\n" << RESET;
}

Dog::Dog(const Dog &other)
{
	std::cout << YELLOW << "Dog(constructor copy call)\n" << RESET;
	type = other.type;
	brain = new Brain();
	brain = other.brain;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << YELLOW << "Dog destroyed\n" << RESET;
}

Dog &Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain();
		brain = other.brain;
		type = other.type;
	}
	return (*this);
}


void	Dog::makeSound(void)
{
	std::cout << YELLOW << "Woaf.....!\n" << RESET;
}
