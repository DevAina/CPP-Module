/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:57:49 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/26 11:04:28 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <ostream>

int	main(void)
{
	std::string	name;

	name = "Splinter";
	DiamondTrap	tr(name);
	name = "Target1";
	tr.attack(name);

	tr.whoAmI();
	std::cout << std::endl;
	std::cout << "\033[32m TEST COPY\033[0m" << std::endl;
	DiamondTrap	cp;
	cp = tr;
	cp.whoAmI();
	return (0);
}
