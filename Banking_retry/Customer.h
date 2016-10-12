#include "Login.h"
#include "Account.h"
#pragma once

class Customer :
	public Login
{
public:
	Customer(std::string username, std::string password, Permission permission);
	~Customer();
	std::vector<Account> m_arr_acct;
	void openSavings();
	void openChequing();
};

