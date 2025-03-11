/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:46:15 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/11 13:31:15 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(): name(), isSigned(false), gradeToSign(130), gradeToexecute(140)
{
}

Form::Form(const std::string nm, const int gradeSign, const int gradeExecute):
    name(nm), isSigned(false), gradeToSign(gradeSign), gradeToexecute(gradeExecute)
{
    if (gradeSign > 150)
        throw Form::GradeTooLowException("\033[1;31mGrade required to sign is too low.\033[0m");
    if (gradeSign < 1)
        throw Form::GradeTooHighException("\033[1;33mGrade required to sign is too high.\033[0m");
    if (gradeExecute > 150)
        throw Form::GradeTooLowException("\033[1;32mGrade required to execute is too low.\033[0m");
    if (gradeExecute < 1)
        throw Form::GradeTooHighException("\33[1;35mGrade required to execute is too high.\033[0m");
}

Form::Form(const Form& other): name(), gradeToSign(130), gradeToexecute(140)
{
    isSigned = other.isSigned;
} 

Form::~Form()
{
}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
        if (gradeToSign > 150)
            throw Form::GradeTooLowException("\033[1;31mGrade required to sign is too low.\033[0m");
        if (gradeToSign < 1)
            throw Form::GradeTooHighException("\033[1;33mGrade required to sign is too high.\033[0m");
        if (gradeToexecute > 150)
            throw Form::GradeTooLowException("\033[1;32mGrade required to execute is too low.\033[0m");
        if (gradeToexecute < 1)
            throw Form::GradeTooHighException("\33[1;35mGrade required to execute is too high.\033[0m");
    }
    return (*this);
}

const std::string   Form::getName() const
{
    return (name);
}

bool    Form::getIsSigned() const
{
    return (isSigned);
}

int   Form::getGradeToSign() const
{
    return (gradeToSign);
}

int   Form::getGradeToExecute() const
{
    return (gradeToexecute);
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException("\033[1;31mGrade required to sign is too low.\033[0m");
    if (bureaucrat.getGrade() <= gradeToSign && !isSigned)
        isSigned = true;
}

Form::GradeTooLowException::GradeTooLowException(const std::string mess): message(mess)
{
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* Form::GradeTooLowException::what() const throw()
{
    return message.c_str();
}

Form::GradeTooHighException::GradeTooHighException(const std::string mess): message(mess)
{
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
    return (message.c_str());
}

std::ostream    &operator<<(std::ostream& o, const Form& form)
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
