/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:02:53 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 18:18:57 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << RED << "Cat(Constructor default)\n" << RESET;
}

Cat::Cat(const Cat &other): Animal(other), brain(NULL)
{
	std::cout << RED << "Cat(constructor copy call)\n" << RESET;
	*this = other;
}

Cat::~Cat(void)
{
	if (brain)
		delete brain;
	std::cout << RED << "Cat destroyed\n" << RESET;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << RED << "Assignement call\n" << RESET;
	if (this != &other)
	{
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
	}
	return (*this);
}


void	Cat::makeSound(void)
{
	std::cout << RED << "Miauuuuuuuuuu Miauuuuuuuuuuuuuuuu.....!\n" << RESET;
}
