/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:29:18 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/06 20:08:33 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

bool	isDigit(std::string &input)

{
    if (input.empty())
        return (false);
    for (char c : input)
    {
        if (!std::isdigit(c))
        {
            std::cout << "Invalid input. Input must be an integer" << std::endl;
            return (false);
        }
    }
    return (true);
}

std::string	getInput(std::string &attribut, int is_digit)
{
    std::string input;

    while (1)
    {
        std::cout << attribut << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input. Please try again" << std::endl;
            continue;
        }
        if (is_digit == 1)
        {
            if (isDigit(input))
                break ;
        }
        else
		{
            if (!input.empty())
                break ;
            else
                std::cout << "This field must not be empty" << std::endl;
        }
    }
    return (input);
}