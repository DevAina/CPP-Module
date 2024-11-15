/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:26:37 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/15 17:27:50 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	if (argc == 2)
	{
		harl.complain(argv[1]);
		return (0);
	}
	else
	{
		std::cerr << "Usage: ./Harl level(DEBUG, WARNING, INFO, ERROR)" << std::endl;
		return (1);
	}
}
