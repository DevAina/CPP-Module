/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:39:28 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/30 12:49:03 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>

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

	public:
		PmergeMe(const int& argc, char **argv);
		~PmergeMe();
		void PrintContainer() const;
};

#endif
