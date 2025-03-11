/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/11 13:50:07 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form    form("Acte de vente", 149, 149);
        Bureaucrat bureaucrat("Splinter", 150);
        std::cout << form << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(form);
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
