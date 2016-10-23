#include "Permission.h"
#include "Customer.h"
#pragma once



class Interface
{
public:
	Interface();
	~Interface();
	/*
	Methods
	*/
	void login(std::string &username, std::string &password);
	int doTransaction();
	float makeWithdraw();
	float howMuchToTransfer();
	float makeADeposit();
	bool otherTransaction();
	bool viewAccounts(Customer *& local_user);
	int selectAnAccount(Customer *& local_user);
	std::string viewOrDoTransactions(Customer *& local_user, int accountKey);
	void viewTransactions(Account *& account);
	bool backToLogin();
	int customerLoggedInScreen();
	std::string customerOpenAccount();

	std::string existingCustomer();
	int displayLoans(Loan *&loan);
	int doTransactionOnLoan();
	int loanPayment();
	int managerLoggedInScreen();
	std::string createCustomerLogin();
	int managerCustomerLoggedInScreen();
	std::string openLoan();
	double amountOfLoan();

};

