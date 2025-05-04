/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:16:30 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/06 07:34:27 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
    std::string name("Bob");

    FragTrap defaultFrag;
    defaultFrag.attack("Target1");
    defaultFrag.highFivesGuys();
    std::cout << std::endl;

    FragTrap paramFrag(name);
    paramFrag.attack("Target2");
    paramFrag.takeDamage(30);
    paramFrag.beRepaired(10);
    paramFrag.highFivesGuys();
    std::cout << std::endl;

    FragTrap copyFrag(paramFrag);
    copyFrag.attack("Target3");
    copyFrag.highFivesGuys();
    std::cout << std::endl;

    FragTrap assignedFrag;
    assignedFrag = paramFrag;
    assignedFrag.attack("Target4");
    assignedFrag.highFivesGuys();
    std::cout << std::endl;

    return (0);
}
