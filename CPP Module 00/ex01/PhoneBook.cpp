/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:43 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/07 15:14:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add(void)
{
	if (currentIndex == 8)
		currentIndex = 0;
    contacts[currentIndex].setAttrinut();
	if (count >= 0 && count <= 8)
		count++;
	currentIndex++;
}

void	PhoneBook::search(void)
{
	int			index;
	std::string	attribut = "Index";
	std::string	input;

	if (count == 0)
	{
		std::cerr << "\033[31m No contact. Please enter Contact \033[0m \n";
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "nickname" << std::endl;
	for (int i = 0 ; i < count ; i++)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].display();
	}

	input = getInput(attribut, 1);
	index = std::stoi(input);
	if (index >= 0 && index < count)
		contacts[index].display_all_infos();
	else
		std::cerr << "\033[31m  Index out of range or Index invalid \033[0m\n";
}
