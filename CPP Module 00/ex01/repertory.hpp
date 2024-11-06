/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 07:35:13 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/06 14:43:07 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPERTORY_HPP
# define REPERTORY_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"
# include "PhoneBook.hpp"

bool    isDigit(std::string &input);
std::string getInput(std::string &attribut, int is_digit);

#endif