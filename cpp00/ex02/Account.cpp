#include "Account.hpp"
#include <iostream>

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
	std::cout << "index:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawls:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
	Account::_amount = initial_deposit;
	Account::_nbAccounts++;

	std::cout << "index:" << Account::getNbAccounts()
		<< ";amount:" << Account::getTotalAmount()
		<< ";created" << std::endl;

}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {
	Account::_nbDeposits++;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (Account::_amount - withdrawal < 0)
		return (false);
	Account::_nbWithdrawals++;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) const {
	return (Account::getTotalAmount());
}

void Account::displayStatus(void) const {
	std::cout << "index:" << Account::_accountIndex
	/*<< ";total:" << Account::_amount; << ";deposits:" << Account::_nbDeposits;
		<< ";withdrawls:" << Account::_nbWithdrawals */<< std::endl;
}