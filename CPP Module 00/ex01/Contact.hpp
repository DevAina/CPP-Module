/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:32:47 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 16:00:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cstring>
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
		std::string	getfirstName(void) const;
		std::string	getlastName(void) const;
		std::string	getnickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getdarkestSecret(void) const;
		void	setfirstName(const std::string& fN);
		void	setlastName(const std::string& lN);
		void	setnickName(const std::string& nN);
		void	setPhoneNumber(const std::string& PN);
		void	setdarkestSecret(const std::string& dS);
};

#endif
