/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:16:04 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 19:55:55 by trarijam         ###   ########.fr       */
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
		~AMateria(void);
		AMateria&	operator=(const AMateria& other);

		std::string	getType(void) const;
		virtual AMateria*	clone(void) = 0;
		virtual void 		use(Icharacter& target) const;
};

#endif
