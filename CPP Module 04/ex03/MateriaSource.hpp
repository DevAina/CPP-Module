/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:35:17 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 20:51:56 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
class	AMateria;

class MateriaSource:public IMateriaSource
{
	private:
		Amateria	*learnedMateria[4];
	
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		~MateriaSource(void);
		MateriaSource	&operator=(const MateriaSource& other);
		void	learnMateria(AMateria* m) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif
