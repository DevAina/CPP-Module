/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:21:41 by trarijam          #+#    #+#             */
/*   Updated: 2025/04/27 18:14:31 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <vector>

class   RPN
{
    private:
        std::vector<std::string>    input;
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
