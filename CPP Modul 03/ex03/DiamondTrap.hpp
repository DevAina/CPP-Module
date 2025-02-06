/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:20:05 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/06 16:10:37 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
#include <string>

class	DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string &nm);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap(void);
		DiamondTrap &operator=(const DiamondTrap& other);
		void	attack(const std::string &target);
		void	whoAmI(void);
};

#endif
