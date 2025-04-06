/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:30:02 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/06 19:36:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	for (std::list<int>::iterator it = ms.begin(); it != ms.end(); ++it)
    	std::cout << *it << " ";
}
