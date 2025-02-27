/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:02:53 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 18:19:47 by trarijam         ###   ########.fr       */
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
	if (this != &other)
	{
		if (brain)
			delete brain;
		brain = new Brain();
		brain = other.brain;
		type = other.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << RED << "Miauuuuuuuuuu Miauuuuuuuuuuuuuuuu.....!\n" << RESET;
}
