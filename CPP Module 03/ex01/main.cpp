/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:52:03 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/04 19:56:38 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
    std::string name("Bob");

    ScavTrap defaultScav;
    defaultScav.attack("Target1");
    defaultScav.guardGate();
    std::cout << std::endl;

    ScavTrap paramScav(name);
    paramScav.attack("Target2");
    paramScav.takeDamage(30);
    paramScav.beRepaired(10);
    paramScav.guardGate();
    std::cout << std::endl;

    ScavTrap copyScav(paramScav);
    copyScav.attack("Target3");
    copyScav.guardGate();
    std::cout << std::endl;

    ScavTrap assignedScav;
    assignedScav = paramScav;
    assignedScav.attack("Target4");
    assignedScav.guardGate();
    std::cout << std::endl;

    return 0;
}
