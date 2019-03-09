#pragma once
#include "Account.h"
class User
{
public:
	User(std::string _name,std::string _address);
	~User();
	int GetUserID() const;
	std::string GetUserName() const;
	std::string GetUserAddress() const;
	void MakeNewAccount(int _accountnum);
	void MakeDeposit(float _amount,int _accountnum);
	int MakeWithdraw(int _amount,int _accountnum,bool canreturn=false);
	void MakeTransfer(int _startacc, int _amount, int _otheracc);
	void FreeAccountMemory();
	int GetNumberOfAccounts() const;
	void DisplayTransactions(int _accountnum);
	void DisplayAllAccounts()const;
private:
	std::string m_name;//heap
	std::string m_address;//heap
	int m_identifier;
	std::vector<Account*> m_accounts;

	int GenerateID();//User generates ID
	Account* GetAccount(int _accountnum);
	void RecordTransaction(int _accountnum,Account::TransactionType _type, float _amount,bool _isvalid);
};

