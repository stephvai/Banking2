#include "stdafx.h"
#include "Loan.h"


Loan::Loan(double amount) {
	principal = amount;
};

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

int Loan::payLoan(Account & account, double amount)
{
	using namespace std;
	if (amount > 0 && account.getBalance() >= amount && amount <= principal) {
		account.withdraw(amount);
		principal -= amount;
		return 0;
	}
	else {
		cout << "Invalid request; verify your principal or account balance" << endl;
		return 1;
	}
}
