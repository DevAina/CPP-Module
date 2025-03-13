/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:30:08 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 15:41:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm():
    AForm("RobotomyRequestForm", 72, 45), target()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string tg):
    AForm("RobotomyRequestForm", 72, 45), target(tg)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
    AForm("RobotomyRequestForm", 72, 45)
{
    target = other.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        target = other.getGradeToSign();
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
    return (target);
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    static bool srandIsinit;
    int randomValue;

    if (!srandIsinit)
    {
        srand(time(0));
        srandIsinit = true;
    }
    if (this->getIsSigned())
    {
        if (executor.getGrade() < this->getGradeToExecute())
        {
            std::cout << "Makes some drilling noises, ";
            randomValue = rand() % 2;
            if (randomValue > 0.5)
                std::cout << "that " << target << " has been robotomized" << std::endl;
            else
                std::cout << "that the robotomy failed" << std::endl;
        }
        else
            throw RobotomyRequestForm::GradeTooLowException("\033[1;36mGrade too low to execute.\033[0m");
    }
    else
        throw RobotomyRequestForm::ExceptionExecute("Form not signes");
}

RobotomyRequestForm::ExceptionExecute::ExceptionExecute(const std::string mess): message(mess)
{
}

RobotomyRequestForm::ExceptionExecute::~ExceptionExecute() throw()
{
}

const char *    RobotomyRequestForm::ExceptionExecute::what() const throw()
{
    return (message.c_str());
}
