// BankManagerAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Bank.h"

int main()
{
	Bank* bank = new Bank();
	std::string name;
	std::string address;
	int num_input = 0;
	float amount;
	int accountchoiceOne;
	int accountchoiceTwo;
	std::cout <<"\t\t\t-----Welcome to the Bank-----"<< std::endl;
	std::cout << "What is your name?";
	std::cin >> name;
	std::cout << "What is your address?";
	std::cin >> address;
	bank->AddUser(new User(name, address));
	std::cout << std::endl;
	
	while (num_input != 7) {
		std::cout << "\tWhat would you like to do?(1-Deposit,2-Withdrawal,3-Transfer,4-Open New Account,5-Transaction History,6-Show Accounts, 7-Exit)\n";
		std::cin >> num_input;
		switch (num_input) {
		case 1:
			if (bank->GetUserByName(name)->GetNumberOfAccounts() > 0) {
				std::cout << "How much would you like to deposit?";
				std::cin >> amount;
				std::cout << "Which account?"<<std::endl;
				bank->GetUserByName(name)->DisplayAllAccounts();
				std::cin >> accountchoiceOne;
				bank->GetUserByName(name)->MakeDeposit(amount, accountchoiceOne);
				std::cout << std::endl;
			}
			else {
				std::cout << "---You must create an account first!---" << std::endl;
			}
			break;
		case 2:
			if (bank->GetUserByName(name)->GetNumberOfAccounts() > 0) {
				std::cout << "How much would you like to withdraw?";
				std::cin >> amount;
				std::cout << "From which account?"<<std::endl;
				bank->GetUserByName(name)->DisplayAllAccounts();
				std::cin >> accountchoiceOne;
				bank->GetUserByName(name)->MakeWithdraw(amount,accountchoiceOne);
				std::cout << std::endl;
			}
			else {
				std::cout << "---You must create an account first!---"<<std::endl;
			}
			break;
		case 3:
			if (bank->GetUserByName(name)->GetNumberOfAccounts() > 0) {
				std::cout << "How much would you like to transfer?";
				std::cin >> amount;
				std::cout << "Transfer from which account?"<<std::endl;
				bank->GetUserByName(name)->DisplayAllAccounts();
				std::cin >> accountchoiceOne;
				std::cout << "Transfer towards which account?"<<std::endl;
				bank->GetUserByName(name)->DisplayAllAccounts();
				std::cin >> accountchoiceTwo;
				bank->GetUserByName(name)->MakeTransfer(accountchoiceOne,amount,accountchoiceTwo);
				std::cout << std::endl;
			}
			else {
				std::cout << "---You must create an account first!---" << std::endl;
			}
			break;
		case 4:
			bank->GetUserByName(name)->MakeNewAccount(bank->GetUserByName(name)->GetNumberOfAccounts() + 1);
			break;
		case 5:
			if (bank->GetUserByName(name)->GetNumberOfAccounts() > 0) {
				std::cout << "Which account history would you like to see?"<<std::endl;
				bank->GetUserByName(name)->DisplayAllAccounts();
				std::cin >> accountchoiceOne;
				bank->GetUserByName(name)->DisplayTransactions(accountchoiceOne);
			}
			else {
				std::cout << "---You must create an account first!---" << std::endl;
			}
			break;
		case 6:
			bank->GetUserByName(name)->DisplayAllAccounts();
			break;
		default:
			break;
		}
	}
	//Free All Memory
	bank->FreeUsersAndAccountsMemory();
	delete bank;
	bank = 0;
}
