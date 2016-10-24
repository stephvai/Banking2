#include "stdafx.h"
#include "User.h"

User::User(std::string username, std::string password, Permission permission):Login(username, password,  permission)
{
	//m_arr_acct.reserve(50);
}


User::~User()
{
}

void User::openSavings()
{
	//Open accounts and push them on the stack
	Account a_temp(Type::Saving);
	m_arr_acct.push_back(a_temp);

}

void User::openChequing()
{
	//Open accounts and push them on the stack
	Account a_temp(Type::Chequing);
	m_arr_acct.push_back(a_temp);
}

void User::openLoan(Account &account, double amount)
{
	loan = new Loan(account, amount);
}

int User::payLoan(Account & account, double amount)
{
	int failure =loan->payLoan(account, amount);
	
	if (loan->principal == 0 && !failure) {
		delete loan;
		loan = nullptr;
		return 0;
	}
	else {
		return 1;
	}
}
