/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:11:16 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/09 17:11:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	type = "Dog";
	std::cout << RED << "Dog(Constructor default)\n" << RESET;
}

Dog::Dog(const Dog &other)
{
	std::cout << RED << "Dog(constructor copy call)\n" << RESET;
	type = other.type;
}

Dog::~Dog(void)
{
	std::cout << RED << "Dog destroyed\n" << RESET;
}

void	Dog::makeSound(void)
{
	std::cout << RED << "Woaf.....!\n" << RESET;
}
