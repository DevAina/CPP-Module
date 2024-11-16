/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:17:37 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/16 17:33:54 by trarijam         ###   ########.fr       */
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
	void (Harl::*complains[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int	index_level = -1;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			index_level = i;
			while (index_level < 4)
			{
				std::cout << "\033[1;33m[" << levels[index_level] << "]\033[0m" << std::endl;
				(this->*complains[index_level])();
				std::cout << "\n";
				index_level++;
			}
			break;
		}
	}
	if (index_level == -1)
	{
		std::cerr << "\033[31mNO APPROPRIATE LEVEL\033[0m" << std::endl;
		return ;
	}	
}
