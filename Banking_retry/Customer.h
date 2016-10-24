#include "Login.h"
#include "Account.h"
#include "Loan.h"
#pragma once

class Customer :
	public Login
{
public:
	Customer(std::string username, std::string password, Permission permission);
	~Customer();
	std::vector<Account> m_arr_acct;
	Loan *loan;
	void openSavings();
	void openChequing();
	void openLoan(Account &account, double amount);
	int payLoan(Account &account, double amount);
};

