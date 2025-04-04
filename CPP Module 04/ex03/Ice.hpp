/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:45 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 11:54:50 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice:public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& other);
		~Ice(void);
		Ice	&operator=(const Ice& other);
		Ice	*clone(void) const;
		void	use(ICharacter& target) const;
};

#endif
