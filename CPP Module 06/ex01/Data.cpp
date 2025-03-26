/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:15:57 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 08:32:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data	initData(const std::string name, std::string const adress,
		const std::string mail, const std::string tel)
{
	t_data	data;

	data.name = name;
	data.address = adress;
	data.mail = mail;
	data.tel = tel;
}
