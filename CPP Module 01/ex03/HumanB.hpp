/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:56:54 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 12:59:44 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class	HumanB
{
	private:
		std::string	_name;
		Weapon		*weapon;
	
	public:
		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon &weapon);
		void	attack(void);
};

#endif
