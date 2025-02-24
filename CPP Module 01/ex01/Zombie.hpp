/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:34 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 09:51:36 by trarijam         ###   ########.fr       */
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

        void    announce() const;
		void	setName(std::string& nm);
		std::string	getName(void) const;
};

#endif
