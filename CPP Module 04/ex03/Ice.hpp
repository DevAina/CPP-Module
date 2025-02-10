/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:52:45 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 20:03:58 by trarijam         ###   ########.fr       */
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
		Ice	*clone(void) const override;
		void	use(Icharacter& target) const override;
};

#endif
