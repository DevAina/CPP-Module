/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:34 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:21:18 by trarijam         ###   ########.fr       */
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

		void	setName(std::string name);
};

#endif
