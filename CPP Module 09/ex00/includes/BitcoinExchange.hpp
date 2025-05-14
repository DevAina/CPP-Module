/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:37:02 by trarijam          #+#    #+#             */
/*   Updated: 2025/05/14 15:44:11 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <ostream>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> container;
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange& other);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        const std::map<std::string, float> getBitcoinExchangeContainer() const;

        bool    dateIsValid(const std::string& date) const;
        bool    valueIsValid(const std::string& value) const;
        float   getExchangeRates(const std::string& date, const std::string& value) const;
};

std::ostream&   operator<<(std::ostream& o, const BitcoinExchange& bitcoin);

#endif
