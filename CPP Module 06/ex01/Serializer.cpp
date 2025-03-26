/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:05:35 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 08:36:05 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other:
	return (*this);
}

uintptr_t	Serializer::serealize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserealize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>raw);
}
