/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:41:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/27 18:43:15 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1 || argc > 2)
	{
		std::cout << "\e[31;1;21mError\e[0m" << std::endl;
		return (1);
	}
	return (0);
}
