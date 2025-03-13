/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:35:10 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/13 17:13:32 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ostream>
#include <iostream>

typedef struct
{
    std::string name;
    AForm*  (*creatForm)(const std::string);
}   tableForm;


static AForm   *getRobotomyRequest(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm   *getPresidentialPardon(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm   *getShrubberyCreation(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

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
    tableForm   form[] ={
        {"RobotomyRequestForm", getRobotomyRequest},
        {"PresidentialPardonForm", getPresidentialPardon},
        {"ShrubberyCreationForm", getShrubberyCreation}
    };

    int legnth = sizeof(form) / sizeof(form[0]);
    for (int i = 0; i < legnth; i++)
    {
        if (nameForm.compare(form[i].name) == 0)
        {
            std::cout << "Intern creates " << form[i].name << std::endl;
            return form[i].creatForm(target);
        }
    }
    throw Intern::InternException("\033[1;31mUnknowForm.\033[0m");
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
