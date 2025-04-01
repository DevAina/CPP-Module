/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:31:46 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/01 14:07:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void    swap(T& a, T& b)
{
    T tmp = b;
    b = a;
    a = tmp;
}

template<typename T>
T   min(T const & a, T const & b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T   max(T const & a, T const & b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif
