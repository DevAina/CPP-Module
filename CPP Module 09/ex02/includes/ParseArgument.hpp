/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseArgument.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:59:32 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/09 10:46:54 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSEARGUMENT_HPP
# define PARSEARGUMENT_HPP

# include <string>
# include <cstdlib>
# include <stdexcept>
# include <limits>

template <typename Container>
void	AddElement(std::string& element, Container& container);

template <typename Container>
void	ParseArgument(const char *arg, Container& container);

template <typename Container>
Container	ParseInput(const int& argc, char **argv);

# include "ParseArgument.tpp"

#endif
