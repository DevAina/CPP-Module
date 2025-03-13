/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:06:56 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/13 11:30:27 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>

class   AForm;

class   Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern  &operator=(const Intern& other);

        AForm   *makeForm(const std::string nameForm, const std::string traget);
        class InternException: public std::exception
        {
            private:
                const std::string message;

            public:
                InternException(const std::string mess);
                ~InternException() throw();
                const char* what() const throw();
        };
};

#endif
