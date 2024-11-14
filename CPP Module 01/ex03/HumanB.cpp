/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:57:01 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:08:22 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <cstdlib>
#include <string>

HumanB::HumanB(std::string name): _name(name)
{
	weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}


void	HumanB::attack(void)
{
	if (weapon == NULL)
	{
		std::cerr << "NO WEAPON" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
}
