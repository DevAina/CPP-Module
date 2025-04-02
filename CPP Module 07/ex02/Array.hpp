/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:29:23 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/02 14:33:48 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
# include <new>
template <typename T>
class   Array
{
    private:
        T*  array;
        unsigned int size;

    public:
        Array();
        Array(const unsigned int n);
        Array(const Array& other);
        ~Array();
        Array   &operator=(const Array& other);
        T&  operator[](int index);
        const T& operator[](int index) const;
        const unsigned int&   getSize() const;
};

# include "Array.tpp"


#endif
