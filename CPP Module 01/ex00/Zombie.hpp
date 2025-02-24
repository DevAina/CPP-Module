/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:07:59 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/23 14:38:27 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	name;
	
	public:
		Zombie(std::string name);
		~Zombie();

		std::string	getName(void) const;
		void	announce(void) const;
};

#endif
