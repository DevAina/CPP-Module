/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:39:28 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/09 10:46:05 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <ctime>
# include <deque>
# include <vector>

# include "ParseArgument.hpp"
# include "Jacobsthal.hpp"
# include "utils.hpp"

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		static std::vector<int>	mergeInsertSortVect(std::vector<int>& container);
		static std::deque<int>		mergeInsertSortDeque(std::deque<int>& container);

	public:
		~PmergeMe();
		static std::vector<int>	ParseForVect(const int& argc, char **argv);
		static std::deque<int>		ParseForDeque(const int& argc, char **argv);
		static std::vector<int>	SortVector(std::vector<int>& container);
		static std::deque<int>		SortDeque(std::deque<int>& container);
};

#endif
