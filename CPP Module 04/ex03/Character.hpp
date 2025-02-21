/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:28:42 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/21 18:37:55 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
# define Character_HPP

# include "ICharacter.hpp"
# include "materiasol.hpp"

class	Character: public ICharacter
{
	private:
		std::string	name;
		AMateria*	inventory[4];
		t_materiasol	*materiasol;

	public:
		Character(void);
		Character(const std::string& nm);
		Character(const Character &other);
		~Character(void);
		Character	&operator=(const Character &other);
		std::string const &getName() const override;
		void	equip(AMateria *m) override;
		void	unequip(int idx) override;
		void	use(int idx, ICharacter& target) override;
};

#endif
