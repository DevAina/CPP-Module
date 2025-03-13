/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:45:06 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 15:54:09 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
    AForm("PresidentialPardonForm", 25, 5), target()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string tg):
    AForm("PresidentialPardonForm", 25, 5), target(tg)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
    AForm("PresidentialPardonForm", 25, 5)
{
    target = other.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        target = other.getGradeToSign();
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
    return (target);
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSigned())
    {
        if (executor.getGrade() < this->getGradeToExecute())
        {
            std::cout << "That " << target  << " has been pardoned by Zaphod Beeblebrox.\n";
        }
        else
            throw PresidentialPardonForm::GradeTooLowException("\033[1;36mGrade too low to execute.\033[0m");
    }
    else
        throw PresidentialPardonForm::ExceptionExecute("Form not signes");
}

PresidentialPardonForm::ExceptionExecute::ExceptionExecute(const std::string mess): message(mess)
{
}

PresidentialPardonForm::ExceptionExecute::~ExceptionExecute() throw()
{
}

const char *    PresidentialPardonForm::ExceptionExecute::what() const throw()
{
    return (message.c_str());
}
