#include "pch.h"
#include "User.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
User::User(std::string _name,std::string _address) 
{
	m_name = _name;
	m_address = _address;
	m_identifier = GenerateID();
}
User::~User()
{
}
int User::GenerateID() 
{
	srand(time(0));
	int idcode = rand() % 9000 + 1000;//1000-9999
	return idcode;
}
int User::GetUserID() const {
	return m_identifier;
}
std::string User::GetUserName() const {
	return m_name;
}
std::string User::GetUserAddress() const {
	return m_address;
}
void User::MakeNewAccount(int _accountnum) {
	//Check if first account
	if (m_accounts.size() == 0) {
		m_accounts.push_back(new Account(_accountnum));
		std::cout << "Account #" << _accountnum << " has been created!" << std::endl;
		return;
	}
	std::vector<Account> invalidaccounts;
	//Check for account below $26
	for (int i = 0; i < m_accounts.size(); i++) {
		if (m_accounts[i]->balance < 25) {
			invalidaccounts.push_back(*m_accounts[i]);
			
			return;
		}
	}
	//display all invalid accounts below $26
	if (invalidaccounts.size() > 0) {
		std::cout << "\t\t\t-----Action cancelled! All following accounts must be greater than $25:-----" << std::endl;
		for (int i = 0; i < invalidaccounts.size();i++) {
			std::cout << "Account #" << invalidaccounts[i].accountNum << std::endl;
		}
		return;
	}
	//Create account if all checks pass
	m_accounts.push_back(new Account(_accountnum));
	std::cout << "Account #"<<_accountnum<<" has been created!" << std::endl;
}
void User::MakeDeposit(float _amount,int _accountnum) {
	//Check if account number is within available boundaries
	if (_accountnum < 1 || _accountnum > m_accounts.size()) {
		std::cout << "Account does not exist!" << std::endl;
		return;
	}
	//Check if deposit amount is greater than 0
	if (_amount < 0) {
		std::cout << "You cannot deposit a number less than zero." << std::endl;
		//Record Transaction
		RecordTransaction(_accountnum, Account::Deposit, _amount, false);
	}
	else {
		float depositAmount = roundf(_amount * 100) / 100;
		GetAccount(_accountnum)->balance += depositAmount;//round 2 decimal places
		std::cout << "You deposited $"<<depositAmount <<" into Account #"<< GetAccount(_accountnum)->accountNum << std::endl;
		//Record Transaction
		RecordTransaction(_accountnum, Account::Deposit, _amount,true);
	}
}
int User::MakeWithdraw(int _amount,int _accountnum,bool _canreturn) {
	//Check if account number is within available boundaries
	if (_accountnum < 1 || _accountnum > m_accounts.size()) {
		std::cout << "Account does not exist!" << std::endl;
		return 0;
	}
	//Check if amount is less than 0
	if (_amount < 0) {
		std::cout << "You cannot withrawn a number less than zero." << std::endl;
		RecordTransaction(_accountnum, Account::Withdraw, _amount, false);
		return 0;
	}
	//Check if amount is an increment of 5 or less than 0
	if(GetAccount(_accountnum)->balance - _amount < 0 || _amount % 5 != 0) {
		std::cout << "Withdrawal failed! Insufficient transaction." << std::endl;
		//Record Transaction
		RecordTransaction(_accountnum, Account::Withdraw, _amount, false);
	}
	else if (_amount % 5 == 0) {
		GetAccount(_accountnum)->balance -= _amount;
		std::cout << "You withdrawn $" << _amount << " from Account #" << GetAccount(_accountnum)->accountNum << std::endl;
		//Record Transaction
		RecordTransaction(_accountnum, Account::Withdraw, _amount, true);
		if (_canreturn) {
			return _amount;
		}
	}
	return 0;
}
void User::MakeTransfer(int _startacc, int _amount, int _otheracc) {
	//Check if account number is within available boundaries
	if (_startacc < 1 ||_startacc > m_accounts.size() || _otheracc < 1 ||_otheracc > m_accounts.size()) {
		std::cout << "Account does not exist!" <<std::endl;
		return;
	}
	int accOneWithdrawal = MakeWithdraw(_amount,_startacc,true);
	MakeDeposit(accOneWithdrawal,_otheracc);
}
void User::RecordTransaction(int _accountnum,Account::TransactionType _type, float _amount,bool _isvalid) {
	GetAccount(_accountnum)->AccountNumbers.push_back(_accountnum);
	GetAccount(_accountnum)->TransactionTypes.push_back(_type);
	GetAccount(_accountnum)->TransactionAmounts.push_back(_amount);
	GetAccount(_accountnum)->TransactionValidity.push_back(_isvalid);
}
Account* User::GetAccount(int _accountnum) {
	for (int i = 0; i < m_accounts.size();i++) {
		if (m_accounts[i]->accountNum == _accountnum) {
			return m_accounts[i];
		}
	}
	return 0;
}
void User::FreeAccountMemory() {
	for (int i = 0; i < m_accounts.size();i++) {
		delete m_accounts[i];
		m_accounts[i] = 0;
	}
}
int User::GetNumberOfAccounts() const{
	return m_accounts.size();
}
void User::DisplayTransactions(int _accountnum) {
	//Check if account number is within available boundaries
	if (_accountnum < 1 || _accountnum > m_accounts.size()) {
		std::cout << "Account does not exist!" << std::endl;
		return;
	}
	GetAccount(_accountnum)->DisplayTransactions(m_name);
}
void User::DisplayAllAccounts() const{
	std::cout << "\t\t\t----User Accounts----" << std::endl;
	if (m_accounts.size() > 0) {
		for (int i = 0; i < m_accounts.size(); i++)
		{
			std::cout << "Account #" << m_accounts[i]->accountNum << ": current balance = " << m_accounts[i]->balance << std::endl;
		}
	}
	std::cout << std::endl;
}
