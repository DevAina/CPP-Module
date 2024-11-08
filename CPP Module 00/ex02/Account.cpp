/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <trarijam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:26 by trarijam          #+#    #+#             */
/*   Updated: 2024/11/08 12:26:38 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

//Initialise variable static
Account::_nbAccounts = 0;
Account::_totalAmount = 0;
Account::_totalNbDeposits = 0;
Account::_totalNbWithdrawals = 0;

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
	return (_nbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_nbWithdrawals);
}

/*
	Display timestamp: format YY/MM/DD_HMS
	--> get time now in seconds (use std::time)
	--> convert time now for struct time_local
*/
void	Account::displayAccountsInfos(void)
{
	std::time_t	now = std::time(0);
	std::tm		*tm = std::localtime(&now);
	std::cout << "[" << (1900 + tm->tm_yday)
						<< (1 + tm->tm_mon)
						<< tm->tm_mday
						<< "_"
						<< tm->tm_hour
						<< tm->tm_min
						<< tm->tm_sec
				<< "] ";
}

