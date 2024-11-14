/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:08:58 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 13:21:33 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address of string: \033[1;33m" << &string << "\033[0m" << std::endl;
	std::cout << "Memory address held by stringPTR: \033[1;32m" << stringPTR << "\033[0m" << std::endl;
	std::cout << "Memory adrress held by stringREF: \033[1;31m" << &string << "\033[0m" << std::endl;
	std::cout << "Value of the string: \033[34m" << string << "\033[0m" << std::endl;
	std::cout << "Value pointed to by stringPTR: \033[34m" << *stringPTR << "\033[0m" << std::endl;
	std::cout << "Value pointed by stringREF: \033[34m" << stringREF << "\033[0m" << std::endl;
	return (0);
}