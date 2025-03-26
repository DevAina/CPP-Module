/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:19:15 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 08:36:16 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data	data;
	uintptr_t	raw;
	Data		*cast;

	data = initData("Splinter", "144 Paris", "splinter@gmail.com", "039792961");
	raw = Serializer::serealize(&data);
	cast = Serializer::deserealize(raw);

	if (cast == &data)
		std::cout << "Cast success" << std::endl;
	else
		std::cout << "Cast Fail" << std::endl;

	std::cout << "name cast: " << cast->name << std::endl;
	return (0);
}
