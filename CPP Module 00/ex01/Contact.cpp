/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 07:35:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/06 15:37:49 by trarijam         ###   ########.fr       */
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
    this->phoneNumber = getInput(attribut.assign("Phone Number"), 1);
    this->darkestSecret = getInput(attribut.assign("Darkest Secret"), 0);
}

void	Contact::display()
{
    std::cout << "First Name: " << this->firstName << std::endl;
    std::cout << "Last Name: " << this->lastName << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}