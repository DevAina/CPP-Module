/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:41:22 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/30 13:02:21 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cerr << "\e[31;1;21mError\e[0m" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	pmerge(argc, argv);
		pmerge.PrintContainer();
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
	}
	return (0);
}
