/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:12:04 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/26 11:05:06 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

typedef struct s_data
{
	std::string name;
	std::string address;
	std::string mail;
	std::string tel;
}	Data;

Data	initData(const std::string name, std::string const adress,
		const std::string mail, const std::string tel);
void	PrintData(Data data);

#endif
