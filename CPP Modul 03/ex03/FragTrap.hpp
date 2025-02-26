/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:06:05 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/25 14:37:32 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string &nm);
		FragTrap(const FragTrap &other);
		~FragTrap(void);
		FragTrap& operator=(const FragTrap& other);
		/*******Redefinition function******/
		void	attack(const std::string& target);

		void highFivesGuys(void);
};

#endif
