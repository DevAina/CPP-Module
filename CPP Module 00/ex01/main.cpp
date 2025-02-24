/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:54:38 by trarijam          #+#    #+#             */
/*   Updated: 2025/01/27 14:48:37 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"
#include <ostream>

int	main(void)
{
    int         width = 40;
	std::string	input;
	std::string	attribut;
    PhoneBook phoneBook;

    while (1)
    {
        if (input.compare("ADD") == 0)
        {
            std::cout << "\033[2J\033[H";
            std::cout << "\033[1;34mContact add in PhoneBook successfully\033[0m" << std::endl;
        }
        else if (input.compare("SEARCH") == 0)
        {
            
        }
        else
            std::cout << "\033[2J\033[H";
        for (int i = 0; i < width; i++)
            std::cout << "\033[32m═\033[0m";
        std::cout << "\n";
        std::cout << "\033[32m║ Phonebook Menu                       ║";
        std::cout << "\n║ Choose an option:                    ║\n";
        std::cout << "║ 1. Add a contact (ADD)               ║\n";
        std::cout << "║ 2. Search for a PhoneBook (SEARCH)   ║\n";
        std::cout << "║ 3. Exit                              ║\033[0m\n"; 
        for (int i = 0; i < width; i++)
            std:: cout << "\033[32m═\033[0m";
		std::cout << "\n";
        input = getInput(attribut.assign("Choice"), 0, 0);
		if (input.compare("ADD") == 0)
			phoneBook.add();
        else if (input.compare("SEARCH") == 0)
            phoneBook.search();
        else if (input.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "\033[31m Choice not valid (ADD or EXIT or SEARCH) \033[0m" << std::endl;
    }
    return (0);
}
