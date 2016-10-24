#include "Login.h"
#include "Account.h"
#include "Loan.h"
#pragma once

class User :
	public Login
{
public:
	User(std::string username, std::string password, Permission permission);
	~User();
	std::vector<Account> m_arr_acct;
	Loan *loan;
	void openSavings();
	void openChequing();
	void openLoan(Account &account, double amount);
	int payLoan(Account &account, double amount);
};

