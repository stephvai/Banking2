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
	bool viewAccounts(Customer *& user);
	int selectAnAccount(Customer *& user);
	std::string viewOrDoTransactions(Customer *& user, int accountKey);
	void viewTransactions(Account *& account);
	bool backToLogin();
	int customerLoggedInScreen();
	std::string customerOpenAccount();

	std::string existingCustomer();

	int managerLoggedInScreen();
	std::string createCustomerLogin();
	int maintenanceLoggedInScreen();
};

