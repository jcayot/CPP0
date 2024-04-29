//
// Created by jules on 28/04/2024.
//

#include "Account.hpp"

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

}

Account::Account(int initial_deposit) {
	this -> _amount = 0;
	this -> _nbDeposits = 0;
	this -> _nbWithdrawals = 0;
	this -> _accountIndex = _nbAccounts++;
	this -> makeDeposit(initial_deposit);
}

Account::~Account(void) {

}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -=withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
	}
	return (false);
}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus(void) const {

}

void Account::_displayTimestamp(void) {

}

Account::Account(void) {

}
