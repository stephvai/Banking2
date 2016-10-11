#include "Login.h"
#include "Account.h"
#pragma once


class Customer :
	public Login
{
public:
	Customer(std::string username, std::string password, Permission permission);
	~Customer();
	std::stack<Account> m_arr_acct;
};

