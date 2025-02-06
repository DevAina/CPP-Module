/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:57:49 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/06 16:33:01 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::string	name;

	name = "Splinter";
	DiamondTrap	tr(name);
	name = "Target1";
	tr.attack(name);

	std::cout << std::endl;
	std::cout << "\033[32m TEST COPY\033[0m" << std::endl;
	DiamondTrap	cp;
	cp = tr;
	cp.whoAmI();
	return (0);
}
