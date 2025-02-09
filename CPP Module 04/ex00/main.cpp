/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:04:14 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/09 17:41:41 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        std::cout << "Test 1: Generic Animal" << std::endl;
        Animal* animal = new Animal();
        animal->makeSound();
        std::cout << "Type: " << animal->getType() << std::endl;
        delete animal;
        std::cout << std::endl;
    }

    {
        std::cout << "Test 2: Dog" << std::endl;
        Dog* dog = new Dog();
        dog->makeSound();
        std::cout << "Type: " << dog->getType() << std::endl;
        delete dog;
        std::cout << std::endl;
    }

    {
        std::cout << "Test 3: Cat" << std::endl;
        Cat* cat = new Cat();
        cat->makeSound();
        std::cout << "Type: " << cat->getType() << std::endl;
        delete cat;
        std::cout << std::endl;
    }

    {
        std::cout << "Test 4: Polymorphism with Animal array" << std::endl;
        Animal* animals[3];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Animal();

        for (int i = 0; i < 3; ++i) {
            animals[i]->makeSound();
            std::cout << "Type: " << animals[i]->getType() << std::endl;
            delete animals[i];
        }
        std::cout << std::endl;
    }

    {
        std::cout << "Test 5: Object copying" << std::endl;
        Dog dog1;
        Dog dog2 = dog1;
        dog2.makeSound();
        std::cout << "Type: " << dog2.getType() << std::endl;

        Cat cat1;
        Cat cat2 = cat1;
        cat2.makeSound();
        std::cout << "Type: " << cat2.getType() << std::endl;
        std::cout << std::endl;
    }

    return (0);
}
