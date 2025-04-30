/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:21:44 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/29 12:38:34 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

static std::list<std::string>::iterator  getOperator(std::list<std::string>& input)
{
    std::list<std::string>::iterator it = input.begin();

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

static bool    isOperator(std::list<std::string>::iterator it)
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

    this->result = 0;
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

int RPN::ProcessCalcul()
{
    if (input.size() == 1)
        return result;

    std::list<std::string>::iterator it = getOperator(input);
    if (it == input.end())
        throw std::runtime_error("\e[1;21;31mError\e[0m");

    if (!isOperator(it))
        throw std::runtime_error("\e[1;21;31mError\e[0m");

    unsigned int dist = std::distance(input.begin(), it);
    if (dist < 2)
        throw std::runtime_error("\e[1;21;31mError\e[0m");

    std::list<std::string>::iterator    it1 = it;
    std::advance(it1, -1);
    std::list<std::string>::iterator    it0 = it1;
    std::advance(it0, -1);

    int operand1 = std::atoi(it0->c_str());
    int operand2 = std::atoi(it1->c_str());

    if (*it == "+")
        result = operand1 + operand2;
    else if (*it == "-")
        result = operand1 - operand2;
    else if (*it == "*")
        result = operand1 * operand2;
    else if (*it == "/")
    {
        if (operand2 == 0)
            throw std::runtime_error("\e[1;21;31mDivision by zero\e[0m");
        result = operand1 / operand2;
    }

    input.erase(it0);
    input.erase(it1);
    input.erase(it);

    std::ostringstream oss;
    oss << result;
    std::list<std::string>::iterator    begin = input.begin();
    std::advance(begin, dist - 2);

    input.insert(begin, oss.str());

    return (ProcessCalcul());
}

