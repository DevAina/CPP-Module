/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:41:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/14 16:54:07 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
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
	std::cout << "\e[21;1;33mSorting of positive integers using std::vector completed in: " << std::fixed
			<< std::setprecision(5) << ((float)(endVect - startVect) / CLOCKS_PER_SEC) << "s.\e[0m" << std::endl;
}

void	SortDeque(int& argc, char **argv)
{
	std::clock_t	startDeque = clock();
	std::deque<int>	containerDeque = PmergeMe::ParseForDeque(argc, argv);		
	containerDeque = PmergeMe::SortDeque(containerDeque);
	std::clock_t	endDeque = clock();
	std::cout << "\e[21;1;32mSorting of positive integers using std::deque completed in: " << std::fixed
			<< std::setprecision(5) << ((float)(endDeque - startDeque) / CLOCKS_PER_SEC) << "s.\e[0m" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "\e[31;1;21mError.\e[0m" << std::endl;
		return (1);
	}
	try
	{
		std::vector<int> vect = PmergeMe::ParseForVect(argc, argv);
		std::cout << "Before: ";
		for (unsigned long i = 0; i < vect.size() ; i++)
		{
			std::cout << vect[i] << " ";
		}
		vect = PmergeMe::SortVector(vect);
		std::cout << "\nAfter: ";
		for (unsigned long i = 0; i < vect.size() ; i++)
		{
			std::cout << vect[i] << " ";
		}
		std::cout << std::endl;
		SortVector(argc, argv);
		SortDeque(argc, argv);
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
