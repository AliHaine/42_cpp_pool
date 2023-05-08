#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	_accountIndex = 0;
int	_amount = 0;
int	_nbDeposits = 0;
int	_nbWithdrawals = 0;

 int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawls:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
	Account::_amount = initial_deposit;
	this->_totalAmount += Account::_amount;
	Account::_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;

	std::cout << "index:" << Account::_accountIndex
		<< ";amount:" << Account::_amount
		<< ";created" << std::endl;
}

Account::~Account(void) {
	std::cout << "index:" << Account::_accountIndex
			  << ";amount:" << Account::_amount
			  << ";closed" << std::endl;
 }

void Account::makeDeposit(int deposit) {
	Account::_nbDeposits++;
	Account::_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (Account::_amount - withdrawal < 0)
		return (false);
	Account::_nbWithdrawals++;
	Account::_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const {
	return (Account::getTotalAmount());
}

void Account::displayStatus(void) const {
	std::cout << "index:" << Account::_accountIndex
		<< ";total:" << Account::_amount
		<< ";deposits:" << Account::_nbDeposits
		<< ";withdrawls:" << Account::_nbWithdrawals << std::endl;
}