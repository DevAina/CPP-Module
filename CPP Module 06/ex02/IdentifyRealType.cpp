/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyRealType.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:14:04 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 15:07:38 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IdentifyRealType.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
#include <typeinfo>

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

void    identify(Base* p)
{
    A*  downcastedA = dynamic_cast<A*>(p);
    B*  downcastedB = dynamic_cast<B*>(p);
    C*  downcastedC = dynamic_cast<C*>(p);
    if (downcastedA != NULL)
    {
        std::cout << "p is A" << std::endl;
        return;
    }
    else if (downcastedB != NULL)
    {
        std::cout << "p is B" << std::endl;
        return ;
    }
    else if (downcastedC != NULL)
    {
        std::cout << "p is C" << std::endl;
        return;
    }
    std::cout << "error pointer" << std::endl;
}

void    identify(Base& ref)
{
    //A
    try
    {
        A &downcastedA = dynamic_cast<A&>(ref);
        (void)downcastedA;
        std::cout << "ref is A" << std::endl;
    }
    catch (std::bad_cast const & err)
    {
    }

    //B
    try
    {
        B &downcastedB = dynamic_cast<B&>(ref);
        (void)downcastedB;
        std::cout << "ref is B" << std::endl;
    }
    catch (std::bad_cast const & err)
    {
    }

    //C
    try
    {
        C &downcastedC = dynamic_cast<C&>(ref);
        (void)downcastedC;
        std::cout << "ref is C" << std::endl;
    }
    catch (std::bad_cast const &err)
    {
    }

}
