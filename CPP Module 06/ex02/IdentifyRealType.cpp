/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyRealType.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:14:04 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/27 07:39:23 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyRealType.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <typeinfo>

#define PURPLE_BOLD "\033[1;35m"
#define YELLOW_BOLD "\033[1;33m"
#define RESET "\033[0m"

Base*   generate(void)
{
    static bool srandIsinit;
    int randomValue;

    if (!srandIsinit)
    {
        srand(time(0));
        srandIsinit = true;
    }
    randomValue = rand() % 3;
    switch (randomValue)
    {
        case 0:
            return (new A());
            break;
        case 1:
            return (new B());
            break;
    }
    return (new C());
}

void identify(Base* p)
{
    A* downcastedA = dynamic_cast<A*>(p);
    B* downcastedB = dynamic_cast<B*>(p);
    C* downcastedC = dynamic_cast<C*>(p);
    
    std::cout << "=======================================" << std::endl;
    if (downcastedA)
    {
        std::cout << PURPLE_BOLD << "=====   Object type: A   =====" << RESET << std::endl;
    }
    else if (downcastedB)
    {
        std::cout << YELLOW_BOLD << "=====   Object type: B   =====" << RESET << std::endl;
    }
    else if (downcastedC)
    {
        std::cout << PURPLE_BOLD << "=====   Object type: C   =====" << RESET << std::endl;
    }
    else
    {
        std::cout << "=====   Unknown object type   =====" << std::endl;
    }
    std::cout << "=======================================" << std::endl;
}

void identify(Base& ref)
{
    std::cout << "=======================================" << std::endl;
    
    try
    {
        A& a = dynamic_cast<A&>(ref);
        (void)a;
        std::cout << PURPLE_BOLD << "=====   Object type: A   =====" << RESET << std::endl;
    }
    catch(const std::bad_cast&) {}
    
    try
    {
        B& b = dynamic_cast<B&>(ref);
        (void)b;
        std::cout << YELLOW_BOLD << "=====   Object type: B   =====" << RESET << std::endl;
    }
    catch(const std::bad_cast&) {}
    
    try
    {
        C& c = dynamic_cast<C&>(ref);
        (void)c;
        std::cout << PURPLE_BOLD << "=====   Object type: C   =====" << RESET << std::endl;
    }
    catch(const std::bad_cast&) {}
    
    std::cout << "=======================================" << std::endl;
}
