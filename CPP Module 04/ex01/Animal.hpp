/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:40:54 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/10 09:27:59 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define RED  "\033[1;31m"
# define GREEN  "\033[1;32m"
# define YELLOW  "\33[1;33m"
# define RESET  "\033[0m"

class Animal
{
	protected:
		std::string	type;
	
	public:
		Animal(void);
		Animal(std::string &tp);
		Animal(const Animal& other);
		virtual ~Animal(void);
		Animal	&operator=(const Animal& other);

		virtual void	makeSound(void) const;
		void	setType(std::string &tp);
		std::string	getType(void) const;
};

#endif
