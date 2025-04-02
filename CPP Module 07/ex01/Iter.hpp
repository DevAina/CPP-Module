/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:43:49 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/02 07:37:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T>
void    iter(T* array, const size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif
