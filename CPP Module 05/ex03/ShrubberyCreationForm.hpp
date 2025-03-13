/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:05:40 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 14:03:33 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <exception>

class ShrubberyCreationForm: public AForm
{
    private:
        std::string   target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm& other);

        std::string getTarget() const;

        void    execute(Bureaucrat const & executor) const;

        class   ExceptionExecute: public std::exception
        {
            private:
                const std::string   message;

            public:
                ExceptionExecute(const std::string mess);
                ~ExceptionExecute() throw();
                const char *    what() const throw();
        };
};

#endif
