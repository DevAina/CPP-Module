/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:18:06 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/09 15:18:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			EnergyPoints;
		int			AttackDammage;
	
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string& name);
		~ClapTrap(void);
		ClapTrap &operator=(const ClapTrap &other);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
