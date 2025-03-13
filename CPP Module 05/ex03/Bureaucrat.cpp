/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:35:15 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 15:44:28 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>
#include <iostream>

Bureaucrat::Bureaucrat(): name("Incognito"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string nm, const int gd): name(nm), grade(gd)
{
    if (gd > 150)
        throw Bureaucrat::GradeTooLowException("Grade is too low. Must be between 150 and 1.");
    if (gd < 1) 
        throw Bureaucrat::GradeTooHighException("Grade is too high. Must be between 150 and 1.");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name()
{
    grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;
    return (*this);
}

const std::string   Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

void    Bureaucrat::incrementGrade(void)
{
    grade -= 1;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException("Grade is too high. Must be between 150 and 1.");
}

void    Bureaucrat::decrementGrade(void)
{
    grade += 1;
    if (grade > 150) 
        throw Bureaucrat::GradeTooLowException("Grade is too low. Must be between 150 and 1.");
}

void    Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << "\033[35mBureaucrat " << name << " signed form " << form.getName() << "\033[0m" << std::endl;
    }
    catch (const AForm::GradeTooLowException& err)
    {
        std::cout << "\033[31mBureaucrat " << name
            << " couldn't sign form " << form.getName() << " " << err.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);
        std::cout << "\033[1;35mBureaucrat " << " executed " << form.getName() << "\033[0m" << std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout << "\033[31mBureaucrat " << name
            << " couldn't execute form " << form.getName() << " " << err.what() << std::endl;
    }
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string ms): mess(ms)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return mess.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string mess): messErreur(mess)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return messErreur.c_str();
}

Bureaucrat::~Bureaucrat()
{

}

std::ostream    &operator<<(std::ostream& o, const Bureaucrat& other)
{
    o << other.getName() << " , bureaucrat grade " << other.getGrade() << ".";
    return (o);
}
