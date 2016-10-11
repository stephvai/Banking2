#include "Customer.h"
#pragma once
class Controller
{
public:
	std::stack <Customer> s_customer; // This will hold all the customers in the program

public:
	Controller();
	~Controller();

	void saveCustomer();
private:
	void saveCustomerAccounts(std::fstream &myFile, Customer &customer);
	void saveCustomerTransactions(std::fstream &myFile, Account &account);


public:
	void loadCustomers();

	/*
	private methods
	*/
private:
	std::stack<Account> loadAccts(std::fstream &myFile, int arr_length);
	std::stack<Transaction> loadAcctsTransactions(std::fstream & myFile, int stackLength);
};

