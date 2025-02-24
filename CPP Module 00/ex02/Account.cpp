/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:35:34 by trarijam          #+#    #+#             */
/*   Updated: 2025/02/24 16:19:56 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <iterator>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
    _totalAmount -= _amount;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
	    		<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals()  << std::endl;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::makeDeposit(int Deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << Deposit << ";";
	_amount += Deposit;
	_nbDeposits++;
	_totalAmount += Deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;	
}

bool	Account::makeWithdrawal(int Withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:";
	if (Withdrawal > checkAmount())
	{
		std::cout << "refused\n";
		return (true);
	}
	std::cout << Withdrawal << ";";
    _amount -= Withdrawal;
    _nbWithdrawals++;
	_totalAmount -= Withdrawal;
	_totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (false);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(0);
	std::tm		*tm = std::localtime(&now);
	std::cout << "[" << (1900 + tm->tm_year)
					<<  (1 + tm->tm_mon)
						<< std::setfill('0') << std::setw(2) << tm->tm_mday
						<< "_"
						<< tm->tm_hour
						<< tm->tm_min
						<< tm->tm_sec
				<< "] ";
}
