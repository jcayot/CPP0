//
// Created by jules on 28/04/2024.
//

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" + std::to_string(_nbAccounts)
		+ ";total:" + std::to_string(_totalAmount)
		+ ";deposits:" + std::to_string(_totalNbDeposits)
		+ ";withdrawals:" + std::to_string(_totalNbWithdrawals) + "\n";
}

Account::Account(int initial_deposit) {
	this -> _amount = initial_deposit;
	this -> _nbDeposits = 0;
	this -> _nbWithdrawals = 0;
	this -> _accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" + std::to_string(this -> _accountIndex)
		+ ";amount:" + std::to_string(initial_deposit)
		+ ";created\n";
}

Account::~Account(void) {
	_nbAccounts--;
	_totalAmount -= this -> _amount;
	_displayTimestamp();
	std::cout << "index:" + std::to_string(this -> _accountIndex)
		+ ";amount:" + std::to_string(this -> _amount)
		+ ";closed\n";
}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" + std::to_string(this -> _accountIndex)
		+ ";p_amount:" + std::to_string(this -> _amount - deposit)
		+ ";deposit:" + std::to_string(deposit)
		+ ";amount:" + std::to_string(this -> _amount)
		+ ";nb_deposits:" + std::to_string(this -> _nbDeposits) + "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -=withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" + std::to_string(this -> _accountIndex)
					 + ";p_amount:" + std::to_string(this -> _amount + withdrawal)
					 + ";withdrawal:" + std::to_string(withdrawal)
					 + ";amount:" + std::to_string(this -> _amount)
					 + ";nb_withdrawals:" + std::to_string(this -> _nbWithdrawals) + "\n";
		return (true);
	}
	return (false);

}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(this -> _accountIndex)
		+ ";amount:" + std::to_string(this -> _amount)
		+ ";deposits:" + std::to_string(this -> _nbDeposits)
		+ ";withdrawals:" + std::to_string(this -> _nbWithdrawals) + "\n";
}

void Account::_displayTimestamp(void) {
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}

Account::Account(void) {

}
