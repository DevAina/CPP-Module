/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:41:05 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/09 10:45:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <algorithm>

template <typename Container,
		typename ContainerJacobsthal>
void	insertElements(Container& mainChain, Container& pend,
		ContainerJacobsthal& insertPos);

template <typename Container,
		 typename OutputCOntainer>
OutputCOntainer	createPair(Container& container);

# include "utils.tpp"

#endif
