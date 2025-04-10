/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:02:36 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/11 12:37:23 by trarijam         ###   ########.fr       */
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
		MutantStack()
		{
		}

		MutantStack(const MutantStack& other): std::stack<T, Container>(other)
		{
		}

		~MutantStack()
		{
		}

		MutantStack	&operator=(const MutantStack& other)
		{
			std::stack<T, Container>::operator=(other);
			return (*this);
		}

		/***iterator**/
		iterator begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}

		/*******Const iterator*************/
		const_iterator	cbegin() const
		{
			return (this->c.cbegin());
		}

		const_iterator	cend() const
		{
			return (this->c.cend());
		}

		/*****************resverse iterator********************/
		reverse_iterator	rbegin()
		{
			return (this->c.rbegin());
		}

		reverse_iterator	rend()
		{
			return (this->c.rend());
		}

		/********************const reverse iterarator***************/
		const_reverse_iterator	rbegin() const
		{
			return (this->c.crbegin());
		}

		const_reverse_iterator	rend() const
		{
			return (this->c.crend());
		}
};

#endif
