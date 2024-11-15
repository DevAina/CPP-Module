/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:17:37 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/15 18:58:14 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "A pizza with every topping imaginable? Count me in! I could eat that thing all day, every day." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I'm so disappointed. I thought I was getting a bacon lover's dream, but this is a bacon nightmare!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I've been a loyal customer here for years. I think it's about time I get rewarded with some extra bacon, free of charge." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is absolutely unacceptable! I demand to speak to your manager immediately!" << std::endl;
}

void	Harl::complain(std::string level)
{
	int	index_level = -1;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			index_level = i;
			break;
		}
	}
	if (index_level == -1)
	{
		std::cerr << "\033[31mNO APPROPRIATE LEVEL\033[0m" << std::endl;
		return ;
	}
	switch (index_level)
	{
		case 0:
			std::cout << "\033[1;32mDEBUG\033[0m" << std::endl;
			debug();
			std::cout << "\n";
			[[fallthrough]];
		case 1:
			std::cout << "\033[1;32mINFO\033[0m" << std::endl;
			info();
			std::cout << "\n";
			[[fallthrough]];
		case 2:
			std::cout << "\033[1;32mWARNING\033[0m" << std::endl;
			warning();
			std::cout << "\n";
			[[fallthrough]];
		case 3:
			std::cout << "\033[1;32mERROR\033[0m" << std::endl;
			error();
			std::cout << "\n";
			break;
		default:
			std::cerr << "NO APPROPRIATE LEVEL" << std::endl;
			break;
	}
}
