/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:42:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/30 13:09:22 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->containerVector = other.containerVector;
		this->containerDeque = other.containerDeque;
	}
	return (*this);
}

void	PmergeMe::AddElement(std::string& element)
{
	long	number;

	if (!element.empty())
	{
		number = atol(element.c_str());
		if (number > std::numeric_limits<int>::max())
			throw	std::invalid_argument("\e[31;1;21mError: Argument not valid. INT_MAX and is limit.\e[0m");
		int cast = static_cast<int>(number);

		this->containerVector.push_back(cast);
		this->containerDeque.push_back(cast);
		element.clear();
	}
}

void	PmergeMe::ParseArgument(const char *arg)
{
	std::string	currentNumber;

	for (int i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] == ' ')
		{
			this->AddElement(currentNumber);
			continue ;
		}
		if (isdigit(arg[i]))
			currentNumber += arg[i];
		else
			throw std::invalid_argument("\e[21;1;31mError: Argument must be digit and positive.\e[0m");
	}
	this->AddElement(currentNumber);
}

void	PmergeMe::ParseInput(const int& argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		this->ParseArgument(argv[i]);
	}
}

PmergeMe::PmergeMe(const int& argc, char **argv)
{
	this->ParseInput(argc, argv);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::PrintContainer() const
{
	std::vector<int>::const_iterator	itVector = this->containerVector.begin();
	std::deque<int>::const_iterator	itDeque = this->containerDeque.begin();
	std::cout << "\e[7;1;42m =============================== Vector ================================\e[0m" << std::endl;
	for ( ; itVector != this->containerVector.end() ; itVector++)
	{
		std::cout << *itVector << " ";
	}
	std::cout << std::endl;

	std::cout << "\e[7;1;42m =============================== Deque =====================================\e[0m" << std::endl;
	for ( ; itDeque != this->containerDeque.end() ; itDeque++)
	{
		std::cout << *itDeque << " ";
	}
	std::cout << std::endl;
}
