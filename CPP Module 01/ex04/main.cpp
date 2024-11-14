/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:38:14 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/14 14:45:35 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	replace(std::string line, std::string old_word, std::string new_word)
{
	size_t			pos = 0;
	std::string	result;

	while (pos < line.length())
	{
		size_t	index_old_word = line.find(old_word, pos);

		if (index_old_word != std::string::npos)
		{
			result.append(line, pos, index_old_word - pos);
			result.append(new_word);
			pos = index_old_word + old_word.length();
		}
		else
		{
			result.append(line.substr(pos));
			break;
		}
	}
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string		old_word = argv[2];
		std::string		new_word = argv[3];
		std::string		output_filename = argv[1];
		std::ifstream	input_file(argv[1]);
		if (!input_file.is_open())
		{
			std::cerr << "Error to open input file." << std::endl; 
			return (1);
		}

		std::ofstream	output_file(output_filename.append(".replace"));
		if (!output_file.is_open())
		{
			std::cerr << "Error to open output file." << std::endl;
			return (1);
		}

		std::string	line;

		while (std::getline(input_file, line))
		{
			line = replace(line, old_word, new_word);
			output_file << line << std::endl;
		}
		input_file.close();
		output_file.close();
		return (0);
	}
	else
	{
		std::cerr << "Error: usage: ./sed_be_gone name_file old_word new_word" << std::endl;
		return (1);
	}
}
