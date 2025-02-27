/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:21:08 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/27 18:10:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>
# include <string>

class Brain
{
	protected:
		std::string	ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain& other);
		~Brain(void);
		Brain	&operator=(const Brain& other);
};

#endif
