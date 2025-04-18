/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:21:44 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/18 15:09:08 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

static std::vector<std::string>::iterator  getOperator(std::vector<std::string>& input)
{
    std::vector<std::string>::iterator it = input.begin();

    for (; it != input.end(); it++)
    {
        std:: string str = *it;
        if (str[0] == '-' || str[0] == '+')
        {
            if (!isdigit(str[1]))
                break;
        }
        else
        {
            if (!isdigit(str[0]))
                break;
        }
    }
    return (it);
}

static bool    isOperator(std::vector<std::string>::iterator it)
{
    if (*it == "+" || *it == "-" || *it == "/" || *it == "*")
        return (true);
    return (false);
}

RPN::RPN(): result(0)
{
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        input = other.input;
        result = other.result;
    }
    return (*this);
}

RPN::RPN(const char *arg)
{
    result = 0;
    char    str[2];
    for (int i = 0; arg[i] != '\0'; i++)
    {
        if (arg[i] == ' ')
            continue ;
        str[0] = arg[i];
        str[1] = '\0';
        input.push_back(str);
    }
}

RPN::~RPN()
{
}

int    RPN::ProcessCalcul()
{
    if (input.size() == 1)
        return (result);
    std::vector<std::string>::iterator it = getOperator(input);
    if (it == input.end())
        return (result);

    /******Check if operande is ok (* + - /)****************/
    if (!isOperator(it))
        throw std::runtime_error("\e[1;21;31mError\e[0m");
    unsigned int    dist = distance(input.begin(), it);
    std::string  str;
    std::string  str1;

    try
    {
        str = input.at(dist - 2);
        str1 = input.at(dist - 1);
    }
    catch (const std::out_of_range& err)
    {
        throw std::runtime_error("\e[1;21;31mError\e[0m");
    }


    if (*it == "+")
        result = atoi(str.c_str()) + atoi(str1.c_str());
    else if (*it == "-")
        result = atoi(str.c_str()) - atoi(str1.c_str());
    else if (*it == "*")
        result = atoi(str.c_str()) * atoi(str1.c_str());
    else if (*it == "/")
        result = atoi(str.c_str()) / atoi(str1.c_str());

    input.erase(input.begin() + (dist - 2));
    input.erase(input.begin() + (dist - 2));
    input.erase(input.begin() + (dist - 2));

    /***********Convert result to string**************/
    std::ostringstream oss;
    oss << result;

    input.insert(input.begin() + (dist - 2), oss.str());
    ProcessCalcul();
    return (result);
}
