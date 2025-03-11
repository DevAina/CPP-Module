/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:22:52 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/11 10:55:02 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include <ostream>

class Form;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string nm, const int gd);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat  &operator=(const Bureaucrat& other);

        const std::string   getName(void) const;
        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);

        /*****For form********/
        void                signForm(Form& form) const;
        /************************/

        class GradeTooHighException: public std::exception
        {
            private:
                std::string messErreur;

            public:
                GradeTooHighException(const std::string mess);
                ~GradeTooHighException() throw();
                const char* what() const throw();
        };

        class   GradeTooLowException: public std::exception
        {
           private:
                 std::string mess;

            public:
                GradeTooLowException(const std::string mess);
                ~GradeTooLowException() throw();
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, const Bureaucrat& other);

#endif
