/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 07:35:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/07 14:31:21 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "repertory.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setAttrinut()
{
    std::string attribut;

    this->firstName = getInput(attribut.assign("Fist Name"), 0);
	this->lastName = getInput(attribut.assign("Last Name"), 0);
    this->nickName = getInput(attribut.assign("Nickname"), 0);
    this->phoneNumber = getInput(attribut.assign("Phone Number"), 1);
    this->darkestSecret = getInput(attribut.assign("Darkest Secret"), 0);
}

void	Contact::display_all_infos(void)
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void    Contact::display(void)
{
    std::cout << std::setw(10) << truncate(firstName) << "|"
                << std::setw(10) << truncate(lastName) << "|"
                << std::setw(10) << truncate(nickName) << "|" << std::endl;
}