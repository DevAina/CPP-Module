/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:40 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/11 11:23:35 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <ostream>
# include <string>

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
        Form(const std::string name, const int gradeSign, const int gradeExecute);
        Form(const Form& other);
        ~Form();
        Form    &operator=(const Form& other);

        /************Getters***********/
        const std::string   getName(void) const;
        bool    getIsSigned(void) const;
        int     getGradeToSign(void) const;
        int     getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat& bureaucrat);

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

std::ostream    &operator<<(std::ostream& o, const Form& form);

#endif
