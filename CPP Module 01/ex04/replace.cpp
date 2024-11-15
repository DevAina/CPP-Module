/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:42:57 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/15 07:02:04 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedBeGone.hpp"

std::string	replace(std::string line, std::string old_word, std::string new_word)
{
	std::string result;
	size_t		pos = 0;

	while (pos < line.length())
	{
		size_t	index_found = line.find(old_word, pos);

		if (index_found != std::string::npos)
		{
			result.append(line, pos, index_found - pos);
			result.append(new_word);
			pos = index_found + old_word.length();
		}
		else
		{
			result.append(line.substr(pos));
			break;
		}
	}
	return (result);
}
