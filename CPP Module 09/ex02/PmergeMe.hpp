/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:39:28 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/03 20:59:23 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <algorithm>
# include <map>
# include <vector>
# include <string>
# include <utility>

template <typename Container>
Container	sequenceJacobsthal(size_t n)
{
	Container	jacobsthal;

	if (n == 0)
		return (jacobsthal);
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	if (n == 1)
		return (jacobsthal);
	for (size_t i = 2; jacobsthal[i - 1] < n; i++)
	{
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i -2]);
		if (jacobsthal[i - 1] + 2 * jacobsthal[i - 2] >= n)
			break ;
	}
	return (jacobsthal);
}


template <typename Container>
Container	generateInsertPosition(Container& jacobsthal, size_t size)
{
	Container	positions;
	size_t	lenJacobsthal = jacobsthal.size();
	typename Container::iterator	end = jacobsthal.end();

	positions.push_back(1);
	for (size_t i = 1; i < lenJacobsthal - 1; i++)
	{
		for (size_t j = jacobsthal[i + 1] - 1; j > jacobsthal[i]; j--)
		{
			if (j <= size)
				positions.push_back(j);
		}
	}
	for (size_t i = size; i > 1; i--)
	{
		if (std::find(jacobsthal.begin(), jacobsthal.end(), i) != end)
			positions.push_back(i);
	}
	return positions;
}

class PmergeMe
{
	private:
		std::vector<int>	containerVector;
		std::deque<int>		containerDeque;
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		void		AddElement(std::string& element);
		void		ParseArgument(const char *argv);
		void		ParseInput(const int& argc, char **argv);

		/********************std::vector******************/
		std::vector<std::pair<int, int> >	createPair(std::vector<int>& container);
		std::vector<int>	mergeInsertSortVect(std::vector<int>& container);
		void	insertElementsVector(std::vector<int>& mainChain, std::vector<int>& pend, std::multimap<size_t, int>& pos);

	public:
		PmergeMe(const int& argc, char **argv);
		~PmergeMe();
		void PrintContainer();
};

#endif
