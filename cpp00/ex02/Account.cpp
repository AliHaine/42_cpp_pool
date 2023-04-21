#include "Account.hpp"

static int Account::getNbAccounts() {
	return this->_nbAccounts;
}

static int Account::getTotalAmount() {
	return this->_totalAmount;
}

static int Account::getNbDeposits() {
	return this->_totalNbDeposits;
}

static int Account::getNbWithdrawals() {
	return this->_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	std::cout << "index:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawls:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
	Account::getTotalAmount() = initial_deposit;

	std::cout << "index:" << Account::getNbAccounts()
		<< ";amount:" << Account::getTotalAmount()
		<< ";created" << std::endl;

}

Account::~Account(void) {}

void Account::makeDeposit(int deposit) {
	Account::getNbDeposits()++;
	Account::getTotalAmount() += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (Account::getTotalAmount() - withdrawal < 0)
		return (false);
	Account::getNbWithdrawals()++;
	Account::getTotalAmount() -= withdrawal;
	return (true);
}

int	Account::checkAmount(void) {
	return (Account::getTotalAmount());
}

static void	Account::displayStatus() {
	std::cout << "index:" << Account::_accountIndex
		<< ";total:" << Account::_amount;
		<< ";deposits:" << Account::_nbDeposits;
		<< ";withdrawls:" << Account::_nbWithdrawals << std::endl;
}