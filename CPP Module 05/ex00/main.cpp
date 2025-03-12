/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 16:20:15 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "Bureaucrat.hpp"

#include <iostream>
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
		std::cout << BOLD << CYAN << "==== Test without exception ===" << RESET << std::endl;
		try
		{
			Bureaucrat b1("John", 50);
			std::cout << GREEN << b1 << RESET << std::endl;

			Bureaucrat b2("Alice", 1);
			std::cout << GREEN << b2 << RESET << std::endl;

			Bureaucrat b3("Bob", 150);
			std::cout << GREEN << b3 << RESET << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& err)
		{
			std::cout << RED << "Exception caught - " << err.what() << RESET << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& err)
		{
			std::cout << RED << "Exception caught - " << err.what() << RESET << std::endl;
		}
		std::cout << "\n\n";
	}

	{
        std::cout << BOLD << CYAN << "==== Test with grade <1 ===" << RESET << std::endl;
        try
		{
            Bureaucrat b4("Charlie", 0);
            std::cout << GREEN << b4 << RESET << std::endl;
        }
		catch (Bureaucrat::GradeTooHighException &e)
		{
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
		std::cout << "\n\n";
	}

	{
		std::cout << BOLD << CYAN << "==== Test with grade >150 ====" << RESET << std::endl;
        try
		{
            Bureaucrat b5("Dave", 151);
            std::cout << GREEN << b5 << RESET << std::endl;
        }
		catch (Bureaucrat::GradeTooLowException &e)
		{
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
		std::cout << "\n\n";
	}

	{
		std::cout << BOLD << CYAN << "==== Test with grade negative ===" << RESET << std::endl;
        try
		{
            Bureaucrat b6("Eve", -10);
            std::cout << GREEN << b6 << RESET << std::endl;
        }
		catch (Bureaucrat::GradeTooHighException &e)
		{
            std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
        }
		std::cout << "\n\n";
	}

	{
		std::cout << BOLD << CYAN << "=== Test to increment grade 1 ===" << RESET << std::endl;
		try
		{
			Bureaucrat	bureaucrat("Bobi", 1);
			std::cout << GREEN << bureaucrat << RESET << std::endl;
			bureaucrat.incrementGrade();	
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
		}
		std::cout << "\n\n";
	}

	{
		std::cout << BOLD << CYAN << "=== Test to decrement grade 150 ===" << RESET << std::endl;
		try
		{
			Bureaucrat	bureaucrat1("Alice", 150);
			std::cout << GREEN << bureaucrat1 << RESET << std::endl;
			bureaucrat1.decrementGrade();	
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << RED << "Exception caught - " << e.what() << RESET << std::endl;
		}
		std::cout << "\n\n";
	}
    return 0;
}
