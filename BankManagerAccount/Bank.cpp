#include "pch.h"
#include "Bank.h"


Bank::Bank()
{
}
Bank::~Bank()
{
}
void Bank::AddUser(User* _user) {
	std::cout << "----New User Created!----\n";
	std::cout << "ID: " << _user->GetUserID()<<std::endl;
	std::cout << "Name: " << _user->GetUserName() << std::endl;
	std::cout << "Address: " << _user->GetUserAddress() << std::endl;
	m_users.push_back(_user);
}
void Bank::FreeUsersAndAccountsMemory() {
	for (int i = 0; i < m_users.size(); i++) {
		m_users[i]->FreeAccountMemory();//free Account memories
		delete m_users[i];//free User memories
		m_users[i] = 0;
	}
}
User* Bank::GetUserByName(std::string _name) {
	for (int i = 0; i < m_users.size();i++) {
		if (m_users[i]->GetUserName() == _name) {
			return (m_users[i]);
		}
	}
	std::cout << "User not found!" << std::endl;
	return 0;
}
User* Bank::GetUserByID(int _id) {
	for (int i = 0; i < m_users.size(); i++) {
		if (m_users[i]->GetUserID() == _id) {
			return m_users[i];
		}
	}
	std::cout << "User not found!"<<std::endl;
	return 0;
}


