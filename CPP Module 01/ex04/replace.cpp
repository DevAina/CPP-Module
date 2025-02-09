/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:42:57 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/09 10:42:19 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedBeGone.hpp"

std::string	replace(std::string line, std::string old_word, std::string new_word)
{
	std::string result;
	size_t		pos = 0;
	size_t		lenOldWord;

	lenOldWord = old_word.length();
	while (pos < line.length())
	{
		size_t	index_found = line.find(old_word, pos);

		if (index_found != std::string::npos)
		{
			result += line.substr(pos, index_found - pos);
			result += new_word;
			pos = index_found + lenOldWord;
		}
		else
		{
			result += line.substr(pos);
			break;
		}
	}
	return (result);
}
