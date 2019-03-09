#pragma once
#include <string>
#include <vector>
#include <iostream>
class Account
{
public:
	enum TransactionType {Withdraw,Deposit};
	Account(int _accountnum);
	~Account();
	float balance;
	std::vector<Account::TransactionType>TransactionTypes;
	std::vector<float>TransactionAmounts;
	std::vector<bool>TransactionValidity;
	std::vector<int>AccountNumbers;
	int accountNum;
	
	void DisplayTransactions(std::string _name);
};

