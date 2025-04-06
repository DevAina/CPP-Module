/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:34:03 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/06 17:36:37 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	private:
		unsigned int	N;
		std::vector<int> container;

	public:
		Span();
		Span(unsigned int nb);
		Span(const Span& other);
		~Span();
		Span	&operator=(const Span& other);
		
		void	addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif
