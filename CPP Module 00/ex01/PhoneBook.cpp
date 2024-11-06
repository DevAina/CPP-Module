/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:28:43 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/06 15:28:37 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "repertory.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add()
{
    if (currentIndex == 8)
    {
        currentIndex = 0;
        contacts[currentIndex].setAttrinut();
    }
    else
        contacts[currentIndex].setAttrinut();
    currentIndex++;
}

void	PhoneBook::display_all()
{
	for (int i = 0; i < 8; i++)
		contacts[i].display();
}
