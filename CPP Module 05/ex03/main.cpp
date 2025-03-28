/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/27 14:57:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

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
    Bureaucrat   bob("Bob", 5);
    Intern intern;
    AForm   *form;

    std::cout << "=================Test with correct Form=============" << std::endl;
    try
    {
        form = intern.makeForm("ShrubberyCreationForm", "home");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
    catch (const Intern::InternException& err)
    {
        std::cout << err.what() << std::endl;
    }

    std::cout << "=================Test with incorrect Form ===================\n";
    try
    {
        form = intern.makeForm("Form", "njewf");
    }
    catch (const Intern::InternException& err)
    {
        std::cout << err.what() << std::endl;
    }
    return (0);
}
