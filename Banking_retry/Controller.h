#include "Customer.h"
#include "Interface.h"
#pragma once
class Controller
{
public:
	std::vector <Customer> s_customer; // This will hold all the customers in the program

	Interface UI;
	std::string user_loggedIn;
	Customer *user = nullptr;
	Customer *workingOn = nullptr;

public:
	Controller();
	~Controller();

	void openAccount();

	void whatUItoDisplay();
	void managerLoggedInScreen();
	void managerExistingCustomer();
	void managerNewCustomer();
	void managerCustomerScreen();
	void closeAccount(Account *&account);
	void customerLoggedInScreen();
	void logOut();
	void viewAccounts();
	void doTransactions(Account *& account);
	void withdrawMoney(Account *& account);
	void transferMoney(Account *& account);
	void makeADeposit(Account *& account);
	void viewTransactions(Account *& account);

	void saveCustomer();
private:
	void saveCustomerAccounts(std::fstream &myFile, Customer &customer);
	void saveCustomerTransactions(std::fstream &myFile, Account &account);
	
	/*
	Methods go here
	*/
public:
	void login();
	void loadCustomers();

	/*
	private methods
	*/
private:
	std::vector<Account> loadAccts(std::fstream &myFile, int arr_length);
	std::vector<Transaction> loadAcctsTransactions(std::fstream & myFile, int stackLength);
};

