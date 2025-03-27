/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:19:15 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/27 07:19:39 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define BOLD    "\033[1;15m"

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

	std::cout << BOLD;
	if (cast != NULL)
		PrintData(*cast);
	std::cout << RESET;
	return (0);
}
