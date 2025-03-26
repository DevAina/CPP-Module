/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:15:57 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 11:07:06 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data	initData(const std::string name, std::string const adress,
		const std::string mail, const std::string tel)
{
	Data	data;

	data.name = name;
	data.address = adress;
	data.mail = mail;
	data.tel = tel;
	return (data);
}

void	PrintData(Data data)
{	
	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Address: " << data.address << std::endl;
	std::cout << "Mail: " << data.mail << std::endl;
	std::cout << "Tel: " << data.tel << std::endl;
}
