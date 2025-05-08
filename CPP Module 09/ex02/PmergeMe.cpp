/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:42:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/08 12:28:04 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
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
	if (this != &other)
	{
		this->containerVector = other.containerVector;
		this->containerDeque = other.containerDeque;
	}
	return (*this);
}

std::vector<int>	PmergeMe::mergeInsertSortVect(std::vector<int>& container)
{
	size_t	lenContainer =container.size();
	if (lenContainer == 1)
		return (container);

	std::vector<std::pair<int, int> >	pairVect = createPair<std::vector<int>, std::vector<std::pair<int, int> > >(container);
	int	rest = -1;
	if (lenContainer % 2 != 0)
		rest = container[lenContainer - 1];
	std::vector<int>	mainChain;
	std::vector<int>	pend;
	size_t	len = pairVect.size();

	for (size_t i = 0; i < len; i++)
	{
		mainChain.push_back(pairVect[i].second);
		if (pairVect[i].first > 0)
			pend.push_back(pairVect[i].first);
	}

	mainChain = mergeInsertSortVect(mainChain);

	for (size_t i = 0; i < len ; i++)
	{
		std::vector<int>::iterator	posinMain = std::find(mainChain.begin(), mainChain.end(), pairVect[i].second);
		std::vector<int>::iterator	posPairPend = std::find(pend.begin(), pend.end(), pairVect[i].first);

		size_t	indexMain = std::distance(mainChain.begin(), posinMain);
		size_t	indexPend = std::distance(pend.begin(), posPairPend);
		if (indexMain != indexPend)
			std::swap(pend[indexMain], pend[indexPend]);
	}

	mainChain.insert(mainChain.begin(), pend[0]);
	pend.erase(pend.begin());

	/*********Generate sequence Jackobsthal*************/
	std::vector<size_t>	jacobsthalNumber = sequenceJacobsthal<std::vector<size_t> >(pend.size());
	std::vector<size_t>	positionNumber = generateInsertPosition<std::vector<size_t> >(jacobsthalNumber, pend.size());	

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

	std::deque<std::pair<int, int> >	pairVect = createPair<std::deque<int>, std::deque<std::pair<int, int> > >(container);
	int	rest = -1;
	if (lenContainer % 2 != 0)
		rest = container[lenContainer - 1];
	std::deque<int>	mainChain;
	std::deque<int>	pend;
	size_t	len = pairVect.size();

	for (size_t i = 0; i < len; i++)
	{
		mainChain.push_back(pairVect[i].second);
		if (pairVect[i].first > 0)
			pend.push_back(pairVect[i].first);
	}

	mainChain = mergeInsertSortDeque(mainChain);

	for (size_t i = 0; i < len ; i++)
	{
		std::deque<int>::iterator	posinMain = std::find(mainChain.begin(), mainChain.end(), pairVect[i].second);
		std::deque<int>::iterator	posPairPend = std::find(pend.begin(), pend.end(), pairVect[i].first);

		size_t	indexMain = std::distance(mainChain.begin(), posinMain);
		size_t	indexPend = std::distance(pend.begin(), posPairPend);
		if (indexMain != indexPend)
		{
			std::swap(pend[indexMain], pend[indexPend]);
		}

	}

	mainChain.insert(mainChain.begin(), pend[0]);
	pend.erase(pend.begin());

	/*********Generate sequence Jackobsthal*************/
	std::deque<size_t>	jacobsthalNumber = sequenceJacobsthal<std::deque<size_t> >(pend.size());
	std::deque<size_t>	positionNumber = generateInsertPosition<std::deque<size_t> >(jacobsthalNumber, pend.size());

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

void	PmergeMe::PrintInfo()
{
	std::vector<int> cpyVect = this->containerVector;
	std::deque<int> cpyDeque = this->containerDeque;

	std::clock_t	startVect = clock();
	cpyVect = this->mergeInsertSortVect(cpyVect);
	std::clock_t	endVect = clock();
	double elapsedsecondsVect = static_cast<double>(endVect - startVect) / CLOCKS_PER_SEC;

	std::clock_t	startDeque = clock();
	cpyDeque = this->mergeInsertSortDeque(cpyDeque);
	std::clock_t	endDeque = clock();	
	double elapsedsecondsDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC;
	std::cout << "\e[7;1;42m =============================== Vector ================================\e[0m" << std::endl;
	for (size_t i = 0; i < cpyVect.size() ; i++)
	{
		std::cout << "[" << cpyVect[i] << "]";
	}
	std::cout << std::endl;

	std::cout << "\e[45m Time to process a range of std::vector of "
		<< this->containerVector.size() << " elments with std::vector: "
		<< std::fixed << std::setprecision(5) << elapsedsecondsVect<< "\e[0m" << std::endl;

	std::cout << "\e[7;1;42m =============================== Deque =====================================\e[0m" << std::endl;
	for (size_t i = 0; i < cpyDeque.size() ; i++)
	{
		std::cout << "[" << cpyDeque[i] << "]";
	}
	std::cout << std::endl;
	std::cout << "\e[45m Time to process a range of std::vector of "
		<< this->containerVector.size() << " elments with std::deque: "
		<< std::fixed << std::setprecision(5) << elapsedsecondsDeque << "\e[0m" << std::endl;
}
