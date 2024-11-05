/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:34 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/05 15:28:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
};
