/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:21:44 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/22 08:42:24 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

static std::deque<std::string>::iterator  getOperator(std::deque<std::string>& input)
{
    std::deque<std::string>::iterator it = input.begin();

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

static bool    isOperator(std::deque<std::string>::iterator it)
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
    std::string currentNumber;

    result = 0;
    for (int i = 0; arg[i] != '\0'; i++)
    {
        if (arg[i] == ' ')
        {
            if (!currentNumber.empty())
            {
                if (currentNumber.size() > 1 ||
                        (atoi(currentNumber.c_str()) > 9 || atoi(currentNumber.c_str()) < 0))
                    throw std::invalid_argument("\e[1;21;31mInvalid argument\e[0m");
                input.push_back(currentNumber);
                currentNumber.clear();
            }
            continue ;
        }
        if (isdigit(arg[i]))
            currentNumber += arg[i];
        else
        {
            if (!currentNumber.empty())
            {
                if (currentNumber.size() > 1 ||
                        (atoi(currentNumber.c_str()) > 9 || atoi(currentNumber.c_str()) < 0))
                    throw std::invalid_argument("\e[1;21;31mInvalid argument\e[0m");
                input.push_back(currentNumber);
                currentNumber.clear();
            }
            input.push_back(std::string(1, arg[i]));
        }
    }
    if (!currentNumber.empty())
    {
        if (currentNumber.size() > 1 ||
                (atoi(currentNumber.c_str()) > 9 || atoi(currentNumber.c_str()) < 0))
            throw std::invalid_argument("\e[1;21;31mInvalid argument\e[0m");
        input.push_back(currentNumber);
        currentNumber.clear();
    }
}

RPN::~RPN()
{
}

int    RPN::ProcessCalcul()
{
    if (input.size() == 1)
        return (result);
    std::deque<std::string>::iterator it = getOperator(input);
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
