/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:41:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/08 14:12:43 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

void	SortVector(int& argc, char **argv)
{
	std::clock_t	startVect = clock();
	std::vector<int>	containerVect = PmergeMe::ParseForVect(argc, argv);		
	containerVect = PmergeMe::SortVector(containerVect);
	std::clock_t	endVect = clock();
	for (size_t	i = 0; i < containerVect.size(); i++)
	{
		std::cout << containerVect[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to range: " << std::fixed
		<< std::setprecision(5) << ((float)(endVect - startVect) / CLOCKS_PER_SEC) << "s" << std::endl;
}

void	SortDeque(int& argc, char **argv)
{
	std::clock_t	startDeque = clock();
	std::deque<int>	containerDeque = PmergeMe::ParseForDeque(argc, argv);		
	containerDeque = PmergeMe::SortDeque(containerDeque);
	std::clock_t	endDeque = clock();
	for (size_t	i = 0; i < containerDeque.size(); i++)
	{
		std::cout << containerDeque[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to range: " << std::fixed
		<< std::setprecision(5) << ((float)(endDeque - startDeque) / CLOCKS_PER_SEC) << "s" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "\e[31;1;21mError\e[0m" << std::endl;
		return (1);
	}
	try
	{
		std::cout << "std::vector" << std::endl;
		SortVector(argc, argv);
		std::cout << "std::deque" << std::endl;
		SortDeque(argc, argv);
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
