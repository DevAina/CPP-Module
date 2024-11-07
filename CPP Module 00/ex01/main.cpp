/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:42:56 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/07 14:36:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"

int main(void)
{
    std::string	input;
	std::string	attribut;
    PhoneBook phoneBook;

    while (1)
    {
        std::cout << "\033[32m Phonebook Menu \033[0m";
        std::cout << "\nChoose an option:\033[0m\n";
        std::cout << "\033[33m 1. Add a contact (ADD)\033[0m\n";
        std::cout << "\033[33m 2. Search for a PhoneBook (SEARCH)\033[0m\n";
        std::cout << "\033[33m 3. Exit \033[0m\n";
		input = getInput(attribut.assign("Choice"), 0);
		if (input.compare("ADD") == 0)
			phoneBook.add();
        else if (input.compare("SEARCH") == 0)
            phoneBook.search();
        else if (input.compare("EXIT") == 0)
			return (0);
		else
			std::cerr << "\033[31m Choice not valid (ADD or EXIT or SEARCH) \033[0m" << std::endl;
    }
    return (0);
}