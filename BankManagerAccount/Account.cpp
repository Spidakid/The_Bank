#include "pch.h"
#include "Account.h"

Account::Account(int _accountnum)
{
	accountNum = _accountnum;
}
Account::~Account()
{
}
void Account::DisplayTransactions(std::string _name) {
	std::cout << "\t\t\t-----Transactions-----"<<std::endl;
	for (int i = 0; i < TransactionTypes.size(); i++) {
		std::cout<< "\t"<< _name<<" ";
		switch (TransactionTypes[i])
		{
		case Account::Withdraw:
			std::cout << "withdrawn ";
			std::cout << TransactionAmounts[i] << " from Account #" << AccountNumbers[i];
			break;
		case Account::Deposit:
			std::cout << "deposits $";
			std::cout << TransactionAmounts[i] << " into Account #" << AccountNumbers[i];
			break;
		default:
			break;
		}
		if (!TransactionValidity[i]) {
			if (TransactionTypes[i] == Account::Deposit) {
				std::cout << " Cannot deposit an amount less than zero";
			}
			else {
				std::cout << " Withdrawal failed! Insufficient transaction.";
			}
		}
		std::cout << std::endl;
	}
}
