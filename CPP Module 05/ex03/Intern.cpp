/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:35:10 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/13 11:30:01 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern::~Intern() {}

Intern  &Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

AForm   *Intern::makeForm(const std::string nameForm, const std::string target)
{
    if (nameForm.compare("RobotomyRequestForm") == 0)
        return new RobotomyRequestForm(target);
    else if (nameForm.compare("PresidentialPardonForm") == 0)
        return new  PresidentialPardonForm(target);
    else if (nameForm.compare("ShrubberyCreationForm") == 0)
        return new ShrubberyCreationForm(target);
    else
        throw Intern::InternException("Unknown form: " + nameForm);
    return (NULL);
}

Intern::InternException::InternException(const std::string mess): message(mess)
{
}

Intern::InternException::~InternException() throw()
{
}

const char  *Intern::InternException::what() const throw()
{
    return message.c_str();
}
