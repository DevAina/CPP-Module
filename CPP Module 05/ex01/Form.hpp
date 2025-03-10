/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:40 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/10 18:45:57 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string.h>

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        bool                isSigned;
        const int          gradeToSign;
        const int           gradeToexecute;

    public:
        Form();
        Form(const std::string name, const int gradeSign, constint gradeExecute);
        Form(const Form& other);
        ~Form();
        Form    &operator=(const Form& other);

        /************Getters***********/
        const std::string   getName(void) const;
        bool    getIsSigned(void) const;
        const int   getGradeToSign(void) const;
        const int   getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat);

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

#endif
