/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:04:29 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/09 15:24:12 by trarijam         ###   ########.fr       */
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
		std::cout << "Usage: ./Harl level(DEBUG, WARNING, INFO, ERROR)" << std::endl;
		return (1);
	}
}
