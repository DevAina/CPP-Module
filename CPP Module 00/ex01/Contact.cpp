/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:23 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 16:01:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "repertory.hpp"
#include <cstring>
#include <string>

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

std::string	Contact::getfirstName(void) const
{
	return (firstName);
}

std::string	Contact::getlastName(void) const
{
	return (lastName);
}

std::string Contact::getnickName(void) const
{
	return (nickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (PhoneNumber);
}

std::string Contact::getdarkestSecret(void) const
{
	return (darkestSecret);
}

void	Contact::setfirstName(const std::string& fN)
{
	firstName = fN;
}

void	Contact::setlastName(const std::string& lN)
{
	lastName = lN;
}

void	Contact::setnickName(const std::string& nN)
{
	nickName = nN;
}

void	Contact::setdarkestSecret(const std::string& dS)
{
	darkestSecret = dS;
}

void	Contact::setPhoneNumber(const std::string& PN)
{
	PhoneNumber = PN;
}
