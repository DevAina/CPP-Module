/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:56 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 15:47:16 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"
# include <exception>

class PresidentialPardonForm: public AForm
{
    private:
        std::string   target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        PresidentialPardonForm   &operator=(const PresidentialPardonForm& other);

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
