#include "stdafx.h"
#include "Loan.h"


Loan::Loan(Account & account, double amount)
{
	if (amount > 0) {
		account.deposit(amount);
		principal = amount;
	}
	else {
		std::cout << "The principal amount must be positive" << std::endl;
	}
}

Loan::~Loan()
{
}

void Loan::payLoan(Account & account, double amount)
{
	using namespace std;
	if (amount > 0 && account.getBalance() >= amount && amount <= principal) {
		account.withdraw(amount);
		principal -= amount;
	}
	else {
		cout << "Invalid request; verify your principal or account balance" << endl;
	}
}
