/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:49:01 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/25 14:16:35 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        container = other.container;
    }
    return (*this);
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream   database;
    std::string     line;

    database.open("data.csv");
    if (!database.is_open())
        throw std::runtime_error("\e[21;1;31m Could not open file DataBase. \e[0m");
    while (std::getline(database, line))
    {
        size_t index = line.find(",");
        if (index == std::string::npos)
        {
        }
        else
        {
            std::string date = line.substr(0, index);
            if (dateIsValid(date))
            {
                float   value = atof(line.substr(index + 1).c_str());
                if (valueIsValid(value))
                    container.insert(std::make_pair(date, value));
            }
        }
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

const std::map<std::string, float> BitcoinExchange::getBitcoinExchangeContainer() const
{
    return (container);
}

bool    BitcoinExchange::dateIsValid(const std::string& date) const
{
    size_t  lenDate = date.length();
    /**********Check length date (10)***********/
    if (lenDate < 10 || lenDate > 10)
        return (false);

    /*************** Check separator date "-" ******************/
    if (date[4] != '-' || date[7] != '-')
        return (false);

    /***************** Check if years/month/day is digit***************************/
    for (unsigned long i = 0; i < lenDate; i++)
    {
        if (date[i] == '-')
        {
            if (i + 1 < lenDate && isdigit(date[i + 1]))
                continue;
            else
                return (false);
        }
        if (!isdigit(date[i]))
            return (false);
    }

    std::string yearString = date.substr(0, 4);
    int year = atoi(yearString.c_str());
    std::string monthString = date.substr(5, 2);
    int month = atoi(monthString.c_str());
    std::string dayString = date.substr(8, 2);
    int day = atoi(dayString.c_str());

    /********CHeck year**************/
    if (year < 0 || (year < 1800 || year >= 2025))
        return (false);
    /***************Check month*********************/
    if (month < 1 || month > 12)
        return (false); 

    /**************Check day***************************/
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
            return (false);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
            return (false);
    }
    if (month == 2)
    {
        if ((month % 4 != 0 && month % 100 != 0) || (month % 4 == 0 && month && 100 == 0 && month % 400 == 0))
        {
            if (day < 1 || day > 29)
                return (false);
        };
    }
    return (true);
}

bool    BitcoinExchange::valueIsValid(const float& value) const
{
   if (value < 0 || value > 1000)
       return (false);
   return (true);
}

float   BitcoinExchange::getExchangeRates(const std::string& date, const float& value) const
{
    float   ExchangeRates;
    std::map<std::string, float>::const_iterator itlow;

    if (!dateIsValid(date))
    {
        std::cout << "\e[31;21;1mBad input: => " << date << "\e[0m"<<std::endl;
        return (-1);
    }
    if (!valueIsValid(value))
    {
        std::cout << "Error: not a positif number or not in the range [0 - 1000]" << "\e[0m" << std::endl;
        return (-1);
    }
    itlow = container.lower_bound(date);
    ExchangeRates = itlow->second;
    if (itlow == container.end())
    {
        itlow--;
        ExchangeRates = itlow->second;
    }
    else if (itlow != container.begin())
    {
        if (itlow->first != date)
            itlow--;
        ExchangeRates = itlow->second;
    }
    return (ExchangeRates);
}

std::ostream&   operator<<(std::ostream& o, const BitcoinExchange& bitcoin)
{
    const std::map<std::string, float>    tmp = bitcoin.getBitcoinExchangeContainer();
    std::map<std::string, float>::const_iterator it = tmp.begin();

    for ( ; it != tmp.end() ; it++)
        o << it->first << "," << it->second << std::endl;
    return (o);
}
