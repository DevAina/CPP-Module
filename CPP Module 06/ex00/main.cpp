/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:47:58 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/27 07:13:00 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::cout << "\033[1:2m";
        ScalarConverter::convert(argv[1]);
        std::cout << "\033[0m";
    }
    return (0);
}
