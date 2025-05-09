/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:07:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/09 11:15:51 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

int main(int argc, char **argv)
{
    try
    {
        BitcoinExchange be;
        std::ifstream   inputFile;
        std::string     line;

        if (argc == 1 || argc > 2)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return (1);
        }
        inputFile.open(argv[1]);
        if (!inputFile.is_open())
            throw std::exception();
        while (std::getline(inputFile, line))
        {
            size_t  index = line.find("|");
            if (index == std::string::npos)
            {
                std::cout << "\e[31;21;1mFormat error, element seperate by \"|\"." << "\e[0m\n";
            }
            else
            {
                std::string date = line.substr(0, index - 1);
                float value = atof(line.substr(index + 1).c_str());
                float ExchangeRate = be.getExchangeRates(date, value);
                if (ExchangeRate >= 0)
                    std::cout << date << " =>" << value << " = " << ExchangeRate * value << std::endl; 
            }
        }
        inputFile.close();
    }
    catch (const std::runtime_error& err)
    {
        std::cout << err.what() << std::endl;
    }
    catch ( ... )
    {
        std::cerr << "Error" << std::endl;
    }
    return (0);
}
