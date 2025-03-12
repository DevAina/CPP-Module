/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:46:15 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 14:07:03 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(): name(), isSigned(false), gradeToSign(130), gradeToexecute(140)
{
}

AForm::AForm(const std::string nm, const int gradeSign, const int gradeExecute):
    name(nm), isSigned(false), gradeToSign(gradeSign), gradeToexecute(gradeExecute)
{
    if (gradeSign > 150)
        throw AForm::GradeTooLowException("\033[1;31mGrade required to sign is too low.\033[0m");
    if (gradeSign < 1)
        throw AForm::GradeTooHighException("\033[1;33mGrade required to sign is too high.\033[0m");
    if (gradeExecute > 150)
        throw AForm::GradeTooLowException("\033[1;32mGrade required to execute is too low.\033[0m");
    if (gradeExecute < 1)
        throw AForm::GradeTooHighException("\33[1;35mGrade required to execute is too high.\033[0m");
}

AForm::AForm(const AForm& other): name(), gradeToSign(130), gradeToexecute(140)
{
    isSigned = other.isSigned;
} 

AForm::~AForm()
{
}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
        if (gradeToSign > 150)
            throw AForm::GradeTooLowException("\033[1;31mGrade required to sign is too low.\033[0m");
        if (gradeToSign < 1)
            throw AForm::GradeTooHighException("\033[1;33mGrade required to sign is too high.\033[0m");
        if (gradeToexecute > 150)
            throw AForm::GradeTooLowException("\033[1;32mGrade required to execute is too low.\033[0m");
        if (gradeToexecute < 1)
            throw AForm::GradeTooHighException("\33[1;35mGrade required to execute is too high.\033[0m");
    }
    return (*this);
}

const std::string   AForm::getName() const
{
    return (name);
}

bool    AForm::getIsSigned() const
{
    return (isSigned);
}

int   AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int   AForm::getGradeToExecute() const
{
    return (gradeToexecute);
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException("\033[1;31mGrade required to sign is too low.\033[0m");
    if (bureaucrat.getGrade() <= gradeToSign && !isSigned)
        isSigned = true;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string mess): message(mess)
{
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return message.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(const std::string mess): message(mess)
{
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return (message.c_str());
}

std::ostream    &operator<<(std::ostream& o, const AForm& form)
{
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string reset = "\033[0m";

    o << "Form: " << form.getName() << std::endl;
    o << "  Signed: ";
    if (form.getIsSigned())
        o << green << "Yes" << reset << std::endl;
    else
        o << red << "No" << reset << std::endl;
    o << "  Grade required to sign: " << form.getGradeToSign() << std::endl;
    o << "  Grade required to execute: " << form.getGradeToExecute();
    return (o);
}
