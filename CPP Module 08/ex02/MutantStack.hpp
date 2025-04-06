/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:02:36 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/06 19:35:25 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>

template <typename T, typename Container = std::list<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
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
};


#endif
