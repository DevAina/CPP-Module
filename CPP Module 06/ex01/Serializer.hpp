/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 07:56:43 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 08:35:49 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		~Serializer();
		Serializer	&operator=(const Serializer& other);
	

	public:
		static uintptr_t	serealize(Data *ptr);
		static Data*		deserealize(uintptr_t raw);
};

#endif
