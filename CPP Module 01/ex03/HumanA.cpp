/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:09:11 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:07:32 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon	&weapon)
{
	_name = name;
	_weapon = &weapon;
}

HumanA::~HumanA() {}


void	HumanA::attack(void)
{
	Weapon	tmp = *_weapon;

	std::cout << _name << " attacks with their " << tmp.getType() << std::endl;
}
