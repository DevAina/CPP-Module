/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:56:02 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/13 13:06:59 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class  Zombie
{
    private:
        std::string	name;

    public:
        Zombie();
        ~ Zombie();

		void	announce(void);
		void	setName(std::string name);
};

#endif
