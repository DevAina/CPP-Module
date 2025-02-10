/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:58:55 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:21 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class	Cat: public Animal
{
	private:
		Brain	*brain;

	public:
		Cat(void);
		Cat(const Cat &other);
		~Cat(void);
		Cat&	operator=(const Cat& other);
		void makeSound(void) override;
};

#endif
