/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:26:40 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 14:29:39 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <exception>

class RobotomyRequestForm: public AForm
{
    private:
        std::string   target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        RobotomyRequestForm   &operator=(const RobotomyRequestForm& other);

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
