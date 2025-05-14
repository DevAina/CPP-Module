/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:42:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/12 12:48:06 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <vector>
#include <ctime>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}

std::vector<int>	PmergeMe::mergeInsertSortVect(std::vector<int>& container)
{
	size_t	lenContainer =container.size();
	if (lenContainer == 1)
		return (container);

	std::vector<int>	pend;
	std::vector<int>	mainChain;
	std::vector<std::pair<int, int> >	pairVect = createMainPend<std::vector<int>, std::vector<std::pair<int, int> > >(container, mainChain, pend);
	int	rest = -1;
	if (lenContainer % 2 != 0)
		rest = container[lenContainer - 1];
	size_t	len = pairVect.size();

	mainChain = mergeInsertSortVect(mainChain);

	for (size_t i = 0; i < len ; i++)
	{
		std::vector<int>::iterator	posinMain = std::find(mainChain.begin(), mainChain.end(), pairVect[i].second);

		size_t	indexMain = std::distance(mainChain.begin(), posinMain);
		pend[indexMain] = pairVect[i].first;
	}

	mainChain.insert(mainChain.begin(), pend[0]);
	pend.erase(pend.begin());

	/*********Generate sequence Jackobsthal*************/
	std::vector<size_t>	positionNumber = generateInsertPosition<std::vector<size_t> >(pend.size());	

	insertElements<std::vector<int>,
		std::vector<size_t> >(mainChain, pend, positionNumber);
	if (rest != -1)
	{	
		size_t	posElementToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), rest) - mainChain.begin();
		mainChain.insert(mainChain.begin() + posElementToInsert, rest);
	}
	return (mainChain);
}

std::deque<int>	PmergeMe::mergeInsertSortDeque(std::deque<int>& container)
{
	size_t	lenContainer =container.size();
	if (lenContainer == 1)
		return (container);

	std::deque<int>	pend;
	std::deque<int>	mainChain;
	std::deque<std::pair<int, int> >	pairVect = createMainPend<std::deque<int>, std::deque<std::pair<int, int> > >(container, mainChain, pend);
	int	rest = -1;
	if (lenContainer % 2 != 0)
		rest = container[lenContainer - 1];
	size_t	len = pairVect.size();

	mainChain = mergeInsertSortDeque(mainChain);
	for (size_t i = 0; i < len ; i++)
	{
		std::deque<int>::iterator	posinMain = std::find(mainChain.begin(), mainChain.end(), pairVect[i].second);

		size_t	indexMain = std::distance(mainChain.begin(), posinMain);
		pend[indexMain] = pairVect[i].first;
	}

	mainChain.insert(mainChain.begin(), pend[0]);
	pend.erase(pend.begin());

	/*********Generate sequence Jackobsthal*************/
	std::deque<size_t>	positionNumber = generateInsertPosition<std::deque<size_t> >(pend.size());

	insertElements<std::deque<int> ,
		std::deque<size_t> >(mainChain, pend, positionNumber);
	if (rest != -1)
	{	
		size_t	posElementToInsert = std::lower_bound(mainChain.begin(), mainChain.end(), rest) - mainChain.begin();
		mainChain.insert(mainChain.begin() + posElementToInsert, rest);
	}
	return (mainChain);
}

PmergeMe::~PmergeMe()
{
}

std::vector<int>	PmergeMe::ParseForVect(const int& argc, char **argv)
{
	std::vector<int>	container = ParseInput<std::vector<int> >(argc, argv);
	return (container);
}

std::deque<int>	PmergeMe::ParseForDeque(const int& argc, char **argv)
{
	std::deque<int>	container = ParseInput<std::deque<int> >(argc, argv);
	return (container);
}

std::vector<int>	PmergeMe::SortVector(std::vector<int>& container)
{
	container = mergeInsertSortVect(container);
	return (container);
}

std::deque<int>	PmergeMe::SortDeque(std::deque<int>& container)
{
	container = mergeInsertSortDeque(container);
	return (container);
}
