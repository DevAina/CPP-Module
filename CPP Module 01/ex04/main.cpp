/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:38:14 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/04 09:20:01 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SedBeGone.hpp"

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
			std::cout << "Error to open input file." << std::endl; 
			return (1);
		}

		std::ofstream	output_file(output_filename.append(".replace"));
		if (!output_file.is_open())
		{
			std::cout << "Error to open output file." << std::endl;
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
		std::cout << "Error: usage: ./sed_be_gone name_file old_word new_word" << std::endl;
		return (1);
	}
}
