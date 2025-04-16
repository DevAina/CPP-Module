/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:06:51 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/16 10:28:26 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span(): N(2000)
{
}

Span::Span(unsigned int n): N(n)
{
}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span()
{
}

Span	&Span::operator=(const Span& other)
{
	if (this != &other)
		N = other.N;
	return (*this);
}

void	Span::addNumber(int number)
{
	if (container.size() >= N)
		throw std::out_of_range("\033[31;1mMaximum capacity reached. Cannot add a new number.\033[0m");
	container.push_back(number);
}

unsigned int	Span::shortestSpan() const
{
	if (container.size() <= 1)
		throw std::logic_error("\033[31;1mNot enough numbers.\033[0m");
	std::vector<int>	tmp = container;
	unsigned int	minDiff;
	unsigned int	diff;

	std::sort(tmp.begin(), tmp.end(), std::greater<int>());
	minDiff = tmp[0] - tmp[1];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		diff = tmp[i] - tmp[i + 1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return (minDiff);
}

unsigned int	Span::longestSpan() const
{
	if (container.size() <= 1)	
		throw std::logic_error("\033[31;1mNot enough numbers.\033[0m");
	unsigned int	maxDiff;
	std::vector<int>	tmp = container;

	std::sort(tmp.begin(), tmp.end());
	maxDiff = tmp[container.size() - 1] - tmp[0];
	return (maxDiff);
}

void	Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((size_t)std::distance(begin, end) < N - container.size())
		throw std::out_of_range("\e[31;1mLen out of range\n");
	container.assign(begin, end);
}
