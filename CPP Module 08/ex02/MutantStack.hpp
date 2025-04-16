/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:02:36 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/16 11:02:48 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack	&operator=(const MutantStack& other);

		/***iterator**/
		iterator begin();

		iterator	end();

		/*******Const iterator*************/
		const_iterator	cbegin() const;

		const_iterator	cend() const;

		/*****************resverse iterator********************/
		reverse_iterator	rbegin();

		reverse_iterator	rend();

		/********************const reverse iterarator***************/
		const_reverse_iterator	crbegin() const;

		const_reverse_iterator	crend() const;
};

# include "MutantStack.tpp"

#endif
