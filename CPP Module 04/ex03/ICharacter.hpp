/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:06:16 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 20:24:42 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

class	ICharacter
{
	public:
		ICharacter(void);
		ICharacter(const ICharacter &other);
		virtual ~ICharacter(void);
		ICharacter	&operator=(const ICharacter &other);
		virtual	std::string const &getName() const = 0;
		virtual	void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif
