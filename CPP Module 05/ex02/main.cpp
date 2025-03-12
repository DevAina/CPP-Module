/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 16:39:40 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
    Bureaucrat highGradeBureaucrat("Alice", 1);
    Bureaucrat midGradeBureaucrat("Bob", 50);
    Bureaucrat lowGradeBureaucrat("Charlie", 150);
    {
        std::cout << BOLD << YELLOW << "\nTest 1: ShrubberyCreationForm" << RESET << std::endl;
        try
        {
            ShrubberyCreationForm shrubberyForm("home");
            std::cout << GREEN << "Form created: " << shrubberyForm << RESET << std::endl;
            midGradeBureaucrat.signForm(shrubberyForm);
            midGradeBureaucrat.executeForm(shrubberyForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 2: RobotomyRequestForm" << RESET << std::endl;
        try
        {
            RobotomyRequestForm robotomyForm("R2D2");
            std::cout << GREEN << "Form created: " << robotomyForm << RESET << std::endl;
            highGradeBureaucrat.signForm(robotomyForm);
            highGradeBureaucrat.executeForm(robotomyForm);
            highGradeBureaucrat.executeForm(robotomyForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 3: PresidentialPardonForm" << RESET << std::endl;
        try
        {
            PresidentialPardonForm pardonForm("Zaphod");
            std::cout << GREEN << "Form created: " << pardonForm << RESET << std::endl;
            lowGradeBureaucrat.signForm(pardonForm);
            lowGradeBureaucrat.executeForm(pardonForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 4: Executing an unsigned form" << RESET << std::endl;
        try
        {
            ShrubberyCreationForm shrubberyForm("garden");
            std::cout << GREEN << "Form created: " << shrubberyForm << RESET << std::endl;
            highGradeBureaucrat.executeForm(shrubberyForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 5: Executing with insufficient grade" << RESET << std::endl;
        try
        {
            RobotomyRequestForm robotomyForm("C3PO");
            std::cout << GREEN << "Form created: " << robotomyForm << RESET << std::endl;

            highGradeBureaucrat.signForm(robotomyForm);
            lowGradeBureaucrat.executeForm(robotomyForm);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }
    return 0;
}
