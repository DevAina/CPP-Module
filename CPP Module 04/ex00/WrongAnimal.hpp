/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:13:56 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/26 16:46:51 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

# define WRONGRED  "\033[0;31m"
# define WRONGGREEN  "\033[0;32m"
# define WRONGYELLOW  "\33[0;33m"
# define WRONGRESET  "\033[0m"

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string tp);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal& other);
		void	makeSound(void) const;
		void	setType(std::string& tp);
		std::string	getType(void) const;
};

#endif
