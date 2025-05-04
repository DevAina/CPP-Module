/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:53:31 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 13:26:55 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int main(void)
{
    std::string bob("Bob");
    std::string limittrap("LimitTrap");

    ClapTrap defaultTrap;
    defaultTrap.attack("Target1");
	defaultTrap.takeDamage(5);
    defaultTrap.beRepaired(3);
    std::cout << std::endl;

    ClapTrap paramTrap(bob);
    bob = "BOB";
    paramTrap.attack("Target2");
    paramTrap.takeDamage(8);
    paramTrap.beRepaired(4);
    std::cout << std::endl;

    ClapTrap copyTrap(paramTrap);
    copyTrap.attack("Target3");
    copyTrap.takeDamage(2);
    copyTrap.beRepaired(1);
    std::cout << std::endl;

    ClapTrap assignedTrap;
    assignedTrap = paramTrap;
    assignedTrap.attack("Target4");
    assignedTrap.takeDamage(3);
    assignedTrap.beRepaired(2);
    std::cout << std::endl;

    ClapTrap limitTrap(limittrap);
    limitTrap.takeDamage(15);
    limitTrap.attack("Target5");
    limitTrap.beRepaired(5);
    std::cout << std::endl;
    return 0;
}
