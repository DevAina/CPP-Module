/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:23 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/18 12:04:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "repertory.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::fillAttribut(void)
{
	std::string	attribut;

	firstName = getInput(attribut.assign("First Name"), 0, 0);
	lastName = getInput(attribut.assign("Last Name"), 0, 0);
	nickName = getInput(attribut.assign("nickanme"), 0, 0);
	PhoneNumber = getInput(attribut.assign("Phone Number"), 0, 1);
	darkestSecret = getInput(attribut.assign("Darkest Secret"), 0, 0);
}

void	Contact::display_all_infos(void)
{
	std::cout << "\n";
	std::cout << "Fist Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void	Contact::display(void)
{
	std::cout << std::setw(10) << truncate(firstName) << "|"
				<< std::setw(10) << truncate(lastName) << "|"
				<< std::setw(10) << truncate(nickName) << "|" << std::endl;
}
