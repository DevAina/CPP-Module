/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:39:28 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/01 21:39:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <map>
# include <vector>
# include <string>
# include <utility>

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
		std::vector<std::pair<int, int> >	createPaire(std::vector<int> &container);
		std::vector<int>	mergeInsertSortVect(std::vector<int>& container);
		std::vector<size_t>	sequenceJacobsthal(size_t n);
		std::vector<size_t>	generateInsertPosition(std::vector<size_t>& sequence, size_t len);
		void	insertElementsVector(std::vector<int>& mainChain, std::vector<int>& pend, std::multimap<size_t, int>& pos);

	public:
		PmergeMe(const int& argc, char **argv);
		~PmergeMe();
		void PrintContainer();
};

#endif
