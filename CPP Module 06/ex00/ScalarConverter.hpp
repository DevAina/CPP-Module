/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:15:32 by trarijam          #+#    #+#             */
/*   Updated: 2025/03/27 07:12:29 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter& other);
        static void    PrintCharConversion(int c);
        static void    PrintConversion(double value, std::string const & literal);

    public:
        static bool    LiteralIsChar(std::string const& literal);
        static bool    LiteralIsInt(std::string const& literal);
        static bool    LiteralIsFloat(std::string const& literal);
        static bool    LiteralIsDouble(std::string const& literal);
        static bool    LiteralIsSpecial(std::string const& literal);
        static void     convert(std::string const literal);
};

#endif
