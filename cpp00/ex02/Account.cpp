//
// Created by Ali Yagmur on 4/4/23.
//

#include "Account.hpp"

static int	Account::getNbAccounts() {
	return this->_nbAccounts;
}

static int	Account::getTotalAmount() {
	return this->_totalAmount;
}

static int	Account::getNbDeposits() {
	return this->_totalNbDeposits;
}

static int	Account::getNbWithdrawals() {
	return this->_totalNbWithdrawals;
}

static void	displayAccountsInfos() {
	std::cout << "Nb accounts:" << getNbDeposits() << std::endl;
	std::cout << "Total amount:" << getTotalAmount() << std::endl;
	std::cout << "Total nb deposits:" << Account::getNbAccounts() << std::endl;
	std::cout << "Total nb withdrawls:" << getNbWithdrawals() << std::endl;
}