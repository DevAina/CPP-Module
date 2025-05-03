/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:42:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/03 21:00:38 by trarijam         ###   ########.fr       */
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

std::vector<std::pair<int, int> >	PmergeMe::createPair(std::vector<int>& container)
{
	std::vector<std::pair<int, int> > vectorPair;
	size_t len = container.size();

	if (len % 2 != 0)
		len -= 1;
	for (size_t i = 0 ; i < len - 1 ; i += 2)
	{
		int	a = container[i];
		int	b = container[i + 1];

		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		std::pair<int, int> pairInt(a, b);
		vectorPair.push_back(pairInt);
	}
	return (vectorPair);
}

std::vector<int>	PmergeMe::mergeInsertSortVect(std::vector<int>& container)
{
	size_t	lenContainer =container.size();
	if (lenContainer == 1)
		return (container);

	std::vector<std::pair<int, int> >	pairVect = this->createPair(container);
	int	rest = -1;
	if (lenContainer % 2 != 0)
		rest = container[lenContainer - 1];
	std::vector<int>	maxPair;
	std::vector<int>	minPair;
	size_t	len = pairVect.size();

	for (size_t i = 0; i < len; i++)
	{
		maxPair.push_back(pairVect[i].second);
		if (pairVect[i].first > 0)
			minPair.push_back(pairVect[i].first);
	}

	maxPair = mergeInsertSortVect(maxPair);

	/*********Generate sequence Jackobsthal*************/
	std::vector<size_t>	jacobsthalNumber = sequenceJacobsthal<std::vector<size_t> >(minPair.size());
	std::vector<size_t>	positionNumber = generateInsertPosition<std::vector<size_t> >(jacobsthalNumber, minPair.size());
	std::multimap<size_t, int>	insertion;

	size_t	lenPositionNumber = positionNumber.size();
	for (size_t i = 0; i < lenPositionNumber ; i++)
		insertion.insert(std::make_pair(positionNumber[i], minPair[i]));


	this->insertElementsVector(maxPair, minPair, insertion);
	if (rest != -1)
	{	
		size_t	posElementToInsert = std::lower_bound(maxPair.begin(), maxPair.end(), rest) - maxPair.begin();
		maxPair.insert(maxPair.begin() + posElementToInsert, rest);
	}
	return (maxPair);
}

/*std::vector<size_t>	PmergeMe::sequenceJacobsthal(size_t n)
{
	std::vector<size_t>	jacobsthal;
	if (n == 0)
		return jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	if (n == 1)
		return (jacobsthal);
	for (size_t i = 2; jacobsthal[i - 1] < n; i++)
	{
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
		if (jacobsthal[i - 1] + 2 * jacobsthal[i - 2] >= n)
			break ;
	}
	return (jacobsthal);
}

std::vector<size_t> PmergeMe::generateInsertPosition(std::vector<size_t>& jacobsthal, size_t size)
{
    std::vector<size_t> positions;

    positions.push_back(1);

    for (size_t i = 1; i < jacobsthal.size() - 1; i++)
    {
        for (size_t j = jacobsthal[i + 1] - 1; j > jacobsthal[i]; j--)
        {
            if (j <= size)
                positions.push_back(j);
        }
    }
	for (size_t i = size ; i > 1 ; i--)
	{
		if (std::find(jacobsthal.begin(), jacobsthal.end(), i) != jacobsthal.end())
			positions.push_back(i);
	}
    return positions;
}*/

void	PmergeMe::insertElementsVector(std::vector<int>& mainChain, std::vector<int>& pend,
		std::multimap<size_t, int>& insertion)
{
	(void)pend;
	std::multimap<size_t, int>::iterator	it = insertion.begin();

	for( ;  it != insertion.end(); it++)
	{	
		size_t	posElementToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), it->second) - mainChain.begin();
		mainChain.insert(mainChain.begin() + posElementToInsert, it->second);
	}
}


PmergeMe::PmergeMe(const int& argc, char **argv)
{
	this->ParseInput(argc, argv);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::PrintContainer()
{
	std::vector<int> tmp = this->containerVector;
	tmp = this->mergeInsertSortVect(tmp);
	std::vector<int>::const_iterator	itVector = this->containerVector.begin();
	std::deque<int>::const_iterator	itDeque = this->containerDeque.begin();
	std::cout << "\e[7;1;42m =============================== Vector ================================\e[0m" << std::endl;
	for ( ; itVector != this->containerVector.end() ; itVector++)
	{
		std::cout << *itVector << " ";
	}
	std::cout << std::endl;
	std::cout << "=== Pair vector ===" << std::endl;
	for (size_t i = 0; i < tmp.size() ; i++)
	{
		std::cout << "[" << tmp[i] << "]";
	}
	std::cout << std::endl;

	std::cout << "\e[7;1;42m =============================== Deque =====================================\e[0m" << std::endl;
	for ( ; itDeque != this->containerDeque.end() ; itDeque++)
	{
		std::cout << *itDeque << " ";
	}
	std::cout << std::endl;
}
