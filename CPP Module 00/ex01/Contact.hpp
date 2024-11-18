/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:32:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/18 12:05:14 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	PhoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		~Contact();

		void	fillAttribut(void);
		void	display_all_infos(void);
		void	display(void);
};

#endif
