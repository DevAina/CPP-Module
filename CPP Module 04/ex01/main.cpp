/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:06:52 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/03 14:27:08 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const int TOTAL_ANIMALS = 10;

    Animal* parks[TOTAL_ANIMALS];

    for (int i = 0; i < TOTAL_ANIMALS; i++)
	{
        if (i < TOTAL_ANIMALS / 2)
            parks[i] = new Dog();
		else
            parks[i] = new Cat();
    }

    for (int i = 0; i < TOTAL_ANIMALS; i++)
        parks[i]->makeSound();

    for (int i = 0; i < TOTAL_ANIMALS; i++)
        delete parks[i];
    Dog dog;
    Dog dog1 = dog;
    dog1.makeSound();
    return (0);
}
