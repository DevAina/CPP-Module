/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/10 14:37:51 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Splinter", 150);
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& err)
    {
        std::cout << err.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& err)
    {
        std::cout << err.what() << std::endl;
    }
}
