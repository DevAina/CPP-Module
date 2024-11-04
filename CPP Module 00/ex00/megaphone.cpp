/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:58:50 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/04 10:06:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

void	megaphone(int argc, char **argv)
{
	int	i;
	int	j;

	for (i = 1 ; i < argc ; i++)
	{
		for (j = 0; argv[i][j] != '\0' ; j++)
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				std::cout << (char)toupper(argv[i][j]);
			else
				std::cout << argv[i][j];
		}
		std::cout << " ";
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		megaphone(argc, argv);
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	std::cout << "\n";
	return (0);
}
