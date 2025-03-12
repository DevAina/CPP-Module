/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 16:30:52 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
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
    {
        std::cout << BOLD << YELLOW << "\nTest 1: Creating a valid form" << RESET << std::endl;
        try
        {
            Form form("Tax Form", 50, 30);
            std::cout << GREEN << "Form created: " << form << RESET << std::endl;
        }
        catch (const Form::GradeTooHighException &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 2: Creating a form with too high grade" << RESET << std::endl;
        try
        {
            Form form("Invalid Form", 0, 30);
            std::cout << GREEN << "Form created: " << form << RESET << std::endl;
        }
        catch (const Form::GradeTooHighException &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 3: Creating a form with too low grade" << RESET << std::endl;
        try
        {
            Form form("Invalid Form", 50, 151);
            std::cout << GREEN << "Form created: " << form << RESET << std::endl;
        }
        catch (const Form::GradeTooHighException &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 4: Bureaucrat signs form successfully" << RESET << std::endl;
        try
        {
            Bureaucrat bureaucrat("Alice", 40);
            Form form("Contract", 50, 30);
			std::cout << GREEN << "Before signing: " << form << RESET << std::endl;
            bureaucrat.signForm(form);
            std::cout << GREEN << "After signing: " << form << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 5: Bureaucrat fails to sign form (grade too low)" << RESET << std::endl;
        try
        {
            Bureaucrat bureaucrat("Bob", 60);
            Form form("Contract", 50, 30);
            std::cout << GREEN << "Before signing: " << form << RESET << std::endl;
            bureaucrat.signForm(form);
            std::cout << GREEN << "After signing: " << form << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }

    {
        std::cout << BOLD << YELLOW << "\nTest 6: Bureaucrat tries to sign an already signed form" << RESET << std::endl;
        try
        {
            Bureaucrat bureaucrat("Charlie", 40);
            Form form("Contract", 50, 30);
            bureaucrat.signForm(form);
            std::cout << GREEN << "After first signing: " << form << RESET << std::endl;
            bureaucrat.signForm(form);
            std::cout << GREEN << "After second signing: " << form << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
    }
    return 0;
}
