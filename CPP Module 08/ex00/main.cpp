/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:49:58 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/03 15:50:23 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    int randomValue;
    int LenContainers = 98;
    std::vector<int> containers;

    srand(time(0));
    for (int i = 0; i < LenContainers ; i++)
    {
        randomValue = rand() % 98;
        containers.push_back(randomValue);
    }

    srand(time(0));
    int endLoop = rand() % 100;
    for (int i = 0; i < endLoop; i++)
    {
        try
        {
            if (i % 2)
                randomValue = rand() % 98;
            else
                randomValue = rand() % 600;
            std::vector<int>::iterator it = easyfind(containers, randomValue);
            std::cout << "\033[43;21;1;30m  ======  Found: " << *it << " ====== \033[0m" << std::endl; 
        }
        catch (const std::out_of_range& err)
        {
            std::cout << err.what() << std::endl;
        }
    }
}
