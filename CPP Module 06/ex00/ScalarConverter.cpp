/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:35:17 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/17 11:01:39 by trarijam         ###   ########.fr       */
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
#include <limits>

static  void    SkipDigits(std::string::const_iterator& it, std::string const& literal)
{
    while (it != literal.end() && isdigit(*it))
        ++it;
}

static bool LiteralIsSpecial(std::string const& literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
            || literal == "-inf" || literal == "+inf" || literal == "nan");
}


static bool    LiteralIsChar(std::string const& literal)
{
    return (literal.length() == 1 && isprint(literal[0]));
}

static bool    LiteralIsInt(std::string const & literal)
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

static void PrinctConversionError(void)
{
    std::cout << "int: impossible" << std::endl;
    std::cout << "char: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void    PrintCharConversion(int c)
{
   if (!isascii(c))
       std::cout << "char: impossible"  << std::endl;
   else if (isprint(c))
       std::cout << "char: " << static_cast<char>(c) << std::endl;
   else
        std::cout << "char: Non displayable" << std::endl;
}

static void    PrintConversion(double value, std::string const& literal)
{
    long longValue;
    float   f;

    //Char
    PrintCharConversion(static_cast<int>(value));
    
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
        if (literal.length() < 7)
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
       if (literal.length() < 7)
            std::cout << ".0" << std::endl;
       else
            std::cout << std::endl;
    }
    else
        std::cout << std::endl;
}

static bool    LiteralIsFloat(std::string const & literal)
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

static bool    LiteralIsDouble(std::string const &literal)
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
    if (it != literal.end())
        return (false);
    return (true);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void    ScalarConverter::convert(std::string const literal)
{
    long    l;
    int     i;
    char    c;
    float   f;
    float   d;

    if (LiteralIsInt(literal))
    {
        l = atol(literal.c_str());
        if (l > INT_MAX || l < INT_MIN)
            PrintConversion(static_cast<double>(l), literal);
        else
        {
            i = atoi(literal.c_str());
            PrintConversion(static_cast<double>(i), literal);
        }
    }
    else if (LiteralIsChar(literal))
    { 
        c = static_cast<char>(literal[0]);
        PrintConversion(static_cast<double>(c), literal);
    }
    else if (LiteralIsFloat(literal))
    {
        f = (float)atof(literal.c_str());
        PrintConversion(static_cast<double>(f), literal);
   }
    else if (LiteralIsDouble(literal))
    {
        d = atof(literal.c_str());
        PrintConversion(d, literal);
    }
    else if (LiteralIsSpecial(literal))
    {
        d = atof(literal.c_str());
        PrintConversion(d, literal);
    }
    else
        PrinctConversionError();
}
