#pragma once
#include "Account.h"
class Loan
{
public:
	Loan(double amount);
	Loan(Account &account, double amount);
	~Loan();
	double interest = 0.08;
	double principal;
	int payLoan(Account &account, double amount);
};

