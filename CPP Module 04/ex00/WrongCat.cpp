/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:27:07 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 11:41:43 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	type = "WrongCat";
	std::cout << WRONGRED << "WrongCat(Constructor default)\n" << WRONGRESET;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << WRONGRED << "WrongCat(constructor copy call)\n" << WRONGRESET;
	type = other.type;
}

WrongCat::~WrongCat(void)
{
	std::cout << WRONGRED << "WrongCat destroyed\n" << WRONGRESET;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << WRONGRED << "Miauuuuuuuuuu Miauuuuuuuuuuuuuuuu.....!\n" << WRONGRESET;
}
