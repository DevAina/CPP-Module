/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:14:51 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/23 11:43:06 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	megaphone(int argc, char **argv)
{
	int	i;
	int	j;

	for (i = 1; i < argc ; i++)
	{
		for (j = 0; argv[i][j] ; j++)
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << "\n";
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		megaphone(argc, argv);
	else
	{
		std::cout << "\033[31m" << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\033[0m" << std::endl;
		return (1);
	}
	return (0);
}

