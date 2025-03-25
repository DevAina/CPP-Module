/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:35:17 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/25 11:08:41 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>

static  void    SkipDigits(std::string::const_iterator& it, std::string const& literal)
{
    while (it != literal.end() && isdigit(*it))
        ++it;
}

bool    ScalarConverter::LiteralIsChar(std::string const& literal)
{
    return (literal.length() == 1 && isprint(literal[0]));
}

bool    ScalarConverter::LiteralIsInt(std::string const & literal)
{
    if (literal.empty())
       return (false);
    std::string::const_iterator   it = literal.begin();
    if (*it == '+' || *it == '-')
        *it++;
    for ( ; it != literal.end(); it++)
    {
        if (!isdigit(*it))
            return (false);
    }
    return (true);
}

void    ScalarConverter::PrintCharConversion(int c)
{
   if (!isascii(c))
       std::cout << "char: impossible"  << std::endl;
   else if (isprint(c))
       std::cout << "char: " << static_cast<char>(c) << std::endl;
   else
        std::cout << "char: Non displayable" << std::endl;
}

void    ScalarConverter::PrintConversion(double value, std::string const& literal)
{
    long longValue;
    float   f;

    //Char
    ScalarConverter::PrintCharConversion(static_cast<int>(value));
    
    //int
    longValue = static_cast<long>(value);
    if (longValue > INT_MAX || longValue < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    //float
    f = static_cast<float>(value);
    std::cout << "float: " << f;
    if (f == longValue)
    {
        if (literal.length() != 7)
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
    else
        std::cout << "f" << std::endl;

    //double
    std::cout << "double: " << value;
    if (value == longValue)
    {
        if (literal.length() != 7)
            std::cout << ".0" << std::endl;
        else
            std::cout << std::endl;
    }
    else
        std::cout << std::endl;
}

bool    ScalarConverter::LiteralIsFloat(std::string const & literal)
{
    if (literal.empty())
        return (false);
    std::string::const_iterator it = literal.begin();
    
    if (*it == '+' || *it == '-')
        *it++;
        
    if (!isdigit(*it))
        return (false);
   
    SkipDigits(it, literal);

    if (*it != '.')
        return (false);
        
    it++;
    if (!isdigit(*it))
        return (false);
 
    SkipDigits(it, literal);

    if (*it != 'f')
        return (false);
    it++;
    if (it != literal.end())
        return (false);

    return (true);
}

bool    ScalarConverter::LiteralIsDouble(std::string const &literal)
{
    std::string::const_iterator it;

    if (literal.empty())
        return (false);

    it = literal.begin();
    if (*it == '+' || *it == '-')
        *it++;

    if (!isdigit(*it))
        return (false);

    SkipDigits(it, literal);

    if (*it != '.')
        return (false);

    *it++;
    if (!isdigit(*it))
        return (false);

    SkipDigits(it, literal);
    if (*it == 'F')
        return (false);
    return (true);
}

void    ScalarConverter::convert(std::string const literal)
{
    char    c;
    float   f;
    float   d;

    if (ScalarConverter::LiteralIsInt(literal))
    {
        long l = atol(literal.c_str());
        ScalarConverter::PrintConversion(static_cast<double>(l), literal);
   }
    else if (ScalarConverter::LiteralIsChar(literal))
    { 
        c = literal[0];
        ScalarConverter::PrintConversion(static_cast<double>(c), literal);
    }
    else if (ScalarConverter::LiteralIsFloat(literal))
    {
        f = (float)atof(literal.c_str());
        ScalarConverter::PrintConversion(static_cast<double>(f), literal);
   }
    else if (ScalarConverter::LiteralIsDouble(literal))
    {
        d = atof(literal.c_str());
        ScalarConverter::PrintConversion(d, literal);
    }
}
