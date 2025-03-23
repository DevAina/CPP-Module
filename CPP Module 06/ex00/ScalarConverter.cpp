/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:35:17 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/23 15:17:35 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <ctype.h>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

bool    ScalarConverter::LiteralIsChar(std::string const& literal)
{
    return (literal.length() == 1 && isprint(literal[0]));
}

bool    ScalarConverter::LiteralIsInt(std::string const & literal)
{
    try
    {
        std::stoi(literal);
        return (true);
    }
    catch (const std::invalid_argument & e)
    {
        return (false);
    }
    catch (const std::out_of_range & e)
    {
        return (false);
    }
}

void    ScalarConverter::convert(std::string const literal)
{
    char    c;
    int     i;
    float   f;
    float   d;

    if (ScalarConverter::LiteralIsChar(literal))
    { 
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(i);
        d = static_cast<double>(f); 
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" <<std::endl;
    }
    else if (ScalarConverter.LiteralIsInt(literal))
    {
        i = std::stoi(literal);
        f = static_cast<float>(i);
        d = static_cast<double>(f);
        if (literal.length() == 1)
        {
            if (isprint(i))
                std::cout << "char: " << static_cast<char>(i) << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" <<std::endl;
    }
}
