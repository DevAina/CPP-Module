/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:29:18 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 14:36:29 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string &nm);
		ScavTrap(const ScavTrap& other);
		~ScavTrap(void);
		/**Redifinition function**/
		void	attack(const std::string& target);

		ScavTrap	&operator=(const ScavTrap& other);
		void		guardGate(void);
};

#endif
