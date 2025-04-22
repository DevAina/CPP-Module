/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:07:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/22 14:27:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    (void)argv;
    std::string     line;
    std::ifstream   dataBase; 

    if (argc == 1 || argc > 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    dataBase.open("data.csv");
    while (std::getline(dataBase, line))
    {
        std::cout << line << std::endl;
    }
    return (0);
}
