#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// needs to get modified to make it init deposit
Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_accountIndex = _nbAccounts++;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"<<_amount<<";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex<<";amount:"<<_amount<<";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::checkAmount() const
{
	return (_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout <<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
	}
	else
	{
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:"<<_accountIndex<<";p_amount:"<<_amount + withdrawal<<";withdrawal:"<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<++_nbWithdrawals<<std::endl;
		return (true);
	}
	return (false);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts <<";total:"<<_totalAmount<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<< _totalNbWithdrawals<<std::endl;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex<<";p_amount:"<<_amount - deposit<<";deposit:"<<deposit<<";amount:"<<_amount<<";nb_deposits:"<<++_nbDeposits<<std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<< std::endl;
}

void Account::_displayTimestamp()
{
    time_t t;
    std::time(&t);
    struct tm *info = std::localtime(&t);
    char buffer[20];
    strftime(buffer, 20, "[%Y%m%d_%H%M%S]", info);
    std::cout <<buffer;
}