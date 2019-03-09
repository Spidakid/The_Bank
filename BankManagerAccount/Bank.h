#pragma once
#include "User.h"
class Bank
{
public:
	Bank();
	~Bank();
	void AddUser(User* _user);
	void FreeUsersAndAccountsMemory();
	User* GetUserByName(std::string _name);
	User* GetUserByID(int _id);
private:
	std::vector<User*> m_users;
};

