/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:14:02 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:05:56 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <cstring>
# include <iostream>
# include <string>

class	HumanA
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
	
		void	attack(void);
};

#endif
