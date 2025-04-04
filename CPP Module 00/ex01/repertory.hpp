/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:58 by trarijam          #+#    #+#             */
/*   Updated: 2025/01/28 08:59:39 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPERTORY_HPP
# define REPERTORY_HPP

# include "Contact.hpp"
# include "PhoneBook.hpp"
# include <iomanip>
# include <unistd.h>
# include <cctype>
# include <iostream>
# include <string>

bool	isphobenumber(std::string &input);
bool	is_digit(std::string &input);
std::string	getInput(std::string &input, int isDigit, int isPhoneNumber);
std::string	truncate(std::string str);

#endif
