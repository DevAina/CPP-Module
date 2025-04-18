/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:21:14 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/18 15:07:51 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    int result;

    if (argc == 1 || argc > 2)
    {
        std::cerr << "\e[21;31mError\e[0m\n";
        return (1);
    }

    RPN rpn(argv[1]);
    try
    {
        result =rpn.ProcessCalcul();
        std::cout << result << std::endl;
    }
    catch (const std::runtime_error& err)
    {
        std::cerr << err.what() << std::endl;
    }
    catch (const std::out_of_range& err)
    {
        std::cerr << err.what() << std::endl;
    }
    catch ( ... )
    {
        std::cerr << "\e[1;21;31mError\e[0m";
    }
    return (0);
}

