/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:16:04 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/11 09:21:49 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMETERIA_HPP
# define AMETERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void);
		AMateria(const std::string& tp);
		AMateria(const AMateria& other);
		virtual ~AMateria(void);
		AMateria	&operator=(const AMateria& other);

		std::string	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void 		use(ICharacter& target) const;
};

#endif
