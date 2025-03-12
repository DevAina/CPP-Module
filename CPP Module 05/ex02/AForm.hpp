/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:40 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/12 14:05:39 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <ostream>
# include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int          gradeToSign;
        const int           gradeToexecute;

    public:
        AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExecute);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm    &operator=(const AForm& other);

        /************Getters***********/
        const std::string   getName(void) const;
        bool    getIsSigned(void) const;
        int     getGradeToSign(void) const;
        int     getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat& bureaucrat);

        virtual void    execute(Bureaucrat const& executor) const = 0;

        class GradeTooHighException: public std::exception
        {
            private:
                std::string message;

            public:
                GradeTooHighException(const std::string mess);
                ~GradeTooHighException() throw();
                const char *    what() const throw();
        };

        class   GradeTooLowException: public std::exception
        {
            private:
                std::string message;

            public:
                GradeTooLowException(const std::string mess);
                ~GradeTooLowException() throw();
                const char*   what() const throw();
        };
};

std::ostream    &operator<<(std::ostream& o, const AForm& form);

#endif
