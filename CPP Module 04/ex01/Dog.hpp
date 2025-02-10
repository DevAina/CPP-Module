/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:11:29 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 08:59:11 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class	Dog: public Animal
{
	private:
		Brain	*brain;

	public:
		Dog(void);
		Dog(const Dog &other);
		~Dog(void);
		Dog&	operator=(const Dog& other);
		void makeSound(void) const override;
};

#endif
