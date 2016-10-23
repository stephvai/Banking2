#pragma once
#include "Account.h"
class Loan
{
public:
	Loan(Account &account, double amount);
	~Loan();
	double interest = 0.08;
	double principal;
	void payLoan(Account &account, double amount);
};

