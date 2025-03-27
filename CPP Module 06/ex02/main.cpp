/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:44:46 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/27 07:38:54 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyRealType.hpp"
#include <iostream>

int main()
{
    Base* obj1 = generate();
    identify(obj1);
    identify(*obj1);
    delete obj1;

    Base* obj2 = generate();
    identify(*obj2);
    identify(obj2);
    delete obj2;

    for (int i = 0; i < 3; i++)
    {
        Base* obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
        std::cout << "\n";
    }

    std::cout << "\n\033[1;31m=== Testing null pointer ===" << "\033[0m" << std::endl;
    Base* nullObj = NULL;
    identify(nullObj);

    return 0;
}
