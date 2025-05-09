/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:21:41 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/29 09:55:08 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <list>

class   RPN
{
    private:
        std::list<std::string>    input;
        int                         result;
        RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN& other);

    public:
        RPN(const char* arg);
        ~RPN();
        int    ProcessCalcul();
};

#endif
