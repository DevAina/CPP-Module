/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:59:48 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/06 17:58:23 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    std::cout << "\033[1;21;7m===== Basic Tests =====\033[0m" << std::endl;
    try
	{
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << " (expected: 2)" << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << " (expected: 14)" << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;21;7m===== Large Dataset Test (10,000 numbers) =====\033[0m" << std::endl;
    try
	{
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(rand());

        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;21;41m===== Overflow Test =====\033[0m" << std::endl;
    try
	{
        Span smallSpan(3);
        smallSpan.addNumber(1);
        smallSpan.addNumber(2);
        smallSpan.addNumber(3);
        smallSpan.addNumber(4);
        std::cout << "Warning: No exception thrown for overflow!" << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;21;41m===== Empty Span Test =====\033[0m" << std::endl;
    try
	{
        Span emptySpan(5);
        std::cout << "Longest span: " << emptySpan.longestSpan() << std::endl;
        std::cout << "Warning: No exception thrown for empty span!" << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[1;21;41m===== Single Value Span Test =====\033[0m" << std::endl;
    try
	{
        Span singleSpan(5);
        singleSpan.addNumber(42);
        std::cout << "Shortest span: " << singleSpan.shortestSpan() << std::endl;
        std::cout << "Warning: No exception thrown for single-value span!" << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    std::cout << "\n\033[21;1;33;7m===== Equal Values Test =====\033[0m" << std::endl;
    try
	{
        Span equalSpan(4);
        equalSpan.addNumber(5);
        equalSpan.addNumber(5);
        equalSpan.addNumber(5);
        equalSpan.addNumber(5);

        std::cout << "Shortest span: " << equalSpan.shortestSpan() << " (expected: 0)" << std::endl;
        std::cout << "Longest span: " << equalSpan.longestSpan() << " (expected: 0)" << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Range Insertion Test =====" << std::endl;
    try
	{
        Span rangeSpan(10);
        int numbers[] = {5, 10, 15, 20, 25};
        size_t  len = sizeof(numbers) / sizeof(numbers[0]);
        for (size_t i = 0; i < len; i++)
            rangeSpan.addNumber(numbers[i]);

        std::cout << "Shortest span: " << rangeSpan.shortestSpan() << " (expected: 5)" << std::endl;
        std::cout << "Longest span: " << rangeSpan.longestSpan() << " (expected: 20)" << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
