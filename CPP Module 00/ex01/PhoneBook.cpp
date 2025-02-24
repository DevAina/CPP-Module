/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:38:55 by trarijam          #+#    #+#             */
/*   Updated: 2025/01/28 08:53:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "repertory.hpp"
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook(): count(0), currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add()
{
	if (currentIndex == 8)
		currentIndex = 0;
	contact[currentIndex].fillAttribut();
	if (count >= 0 && count <= 7)
		count++;
	currentIndex++;
}

void	PhoneBook::search()
{
	int		index;
	std::string	attribut = "Index";
	std::string	input;

	if (count == 0)
	{
		std::cout << "\033[31m No contact. Please enter Contact. \n" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "nickname" << std::endl;
	for (int i = 0 ; i < count ; i++)
	{
		std::cout << std::setw(10) << i << "|";
		contact[i].display();
	}
	input = getInput(attribut, 1, 0);

	index = std::atoi(input.c_str());
	if (index >= 0 && index < count)
		contact[index].display_all_infos();
	else
		std::cout << "\033[31m  Index out of range or Index invalid \033[0m\n";
}
