/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:43:19 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/09 15:23:44 by trarijam         ###   ########.fr       */
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

	std::string	levels[4] = { "DEBUG" , "INFO" , "WARNING" , "ERROR"};
	for (int i = 0; i < 4 ; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*complains[i])();
			return ;
		}
	}
	std::cout << "NO APPROPRIATE LEVEL" << std::endl;
}
