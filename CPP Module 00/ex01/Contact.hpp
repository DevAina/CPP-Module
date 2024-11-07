/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:34 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/07 14:28:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
    private:
		std::string	firstName;
        std::string	lastName;
        std::string	nickName;
        std::string	phoneNumber;
        std::string	darkestSecret;

    public:
		//constructor
        Contact();
		//destructor
        ~Contact();

		//set atrribut
		void	setAttrinut();
        void    display_all_infos();
        void    display();
};

#endif