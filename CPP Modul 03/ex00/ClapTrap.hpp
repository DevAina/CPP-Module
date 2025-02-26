/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:18:06 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 13:21:54 by trarijam         ###   ########.fr       */
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
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDammage(void) const;
		void		setName(std::string nm);
		void		setHitPoijnts(int hp);
		void		setEnergyPoints(int ep);
		void		setAttackDammage(int ad);
};

#endif
