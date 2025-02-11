/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:36:23 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 13:39:35 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(void) {}

ICharacter::ICharacter(const ICharacter& other)
{
	(void)other;
}

ICharacter::~ICharacter() {}

ICharacter &ICharacter::operator=(const ICharacter& other)
{
	(void)other;
	return (*this);
}
