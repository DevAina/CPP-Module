/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:34 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/06 14:52:42 by trarijam         ###   ########.fr       */
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
        std::string	phoneNumber;
        std::string	darkestSecret;

    public:
		//constructor
        Contact();
		//destructor
        ~Contact();

		//set atrribut
		void	setAttrinut();

        void    display();
};

#endif