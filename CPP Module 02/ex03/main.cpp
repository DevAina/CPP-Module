/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:07:55 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/21 09:48:19 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "Fixed.hpp"

int main()
{
    Fixed a(5.25f);
    Fixed b(2.5f);

    //Comparason operator
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    // operator arithmetiaue: * + - /
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    // Incermentation and decremetation
    Fixed c = a;
    std::cout << "Pré-incrémentation: " << ++c << std::endl;
    std::cout << "Post-incrémentation: " << c++ << std::endl;
    std::cout << "Après post-incrémentation: " << c << std::endl;

    std::cout << "Pré-décrémentation: " << --c << std::endl;
    std::cout << "Post-décrémentation: " << c-- << std::endl;
    std::cout << "Après post-décrémentation: " << c << std::endl;

    const Fixed d(1.75f);
    const Fixed e(3.5f);

    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;

    return 0;
}
