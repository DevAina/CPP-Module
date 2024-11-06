/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:42:56 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/06 15:46:18 by trarijam         ###   ########.fr       */
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
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Add a contact: \n";
        std::cout << "2. Search for a contact\n";
        std::cout << "3. Display all contacts\n";
        std::cout << "4. Exit\n";
		input = getInput(attribut.assign("Choice"), 0);
		if (input.compare("ADD"))
			phoneBook.add();
		else if (input.compare("EXIT"))
			return (0);
		else
		{
			std::cout << "Choice not valid (ADD or EXIT)" << std::endl;
		}
    }
    return (0);
}