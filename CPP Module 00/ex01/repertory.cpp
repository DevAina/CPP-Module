/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:42:52 by trarijam          #+#    #+#             */
/*   Updated: 2025/01/28 08:59:09 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"
#include <iostream>

bool	isphonenumber(std::string input)
{
	if (input.empty())
		return (false);
	if (input.length() < 10)
	{
		std::cout << "\033[31mInvalid phone number format.\033[0m" << std::endl;
		return (false);
	}
	if (!is_digit(input))
		return (false);
	return (true);
}

bool	is_digit(std::string &input)
{
	const char	*str = input.c_str();

	if (input.empty())
		return (false);
	for (int i = 0; str[i] != '\0' ; i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "\033[31m Invalid input. Input must be an integer \033[0m" << std::endl;
			return (false);
		}
	}
	return (true);
}

std::string	getInput(std::string &attribut, int isDigit, int isPhoneNumber)
{
	std::string	input;

	while (1)
	{
		std::cout << attribut << ": ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\033[31mError\033[0m" << std::endl;
			_exit(1);
		}
		if (isDigit)
		{
			if (is_digit(input))
				break;
		}
		else if (isPhoneNumber)
		{
			if (isphonenumber(input))
				break;
		}
		else
		{
			if (!input.empty())
				break ;
			else
				std::cout <<  "\033[31m This field must not be empty \033[0m" << std::endl;
		}
	}
	return (input);
}
