/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:06:52 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 09:14:41 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const int TOTAL_ANIMALS = 10;

    Animal* zoo[TOTAL_ANIMALS];

    for (int i = 0; i < TOTAL_ANIMALS; i++)
	{
        if (i < TOTAL_ANIMALS / 2)
            zoo[i] = new Dog();
		else
            zoo[i] = new Cat();
    }

    for (int i = 0; i < TOTAL_ANIMALS; i++)
        zoo[i]->makeSound();

    for (int i = 0; i < TOTAL_ANIMALS; i++)
        delete zoo[i];
    return (0);
}
