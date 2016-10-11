#include "Customer.h"
#include "Interface.h"
#pragma once
class Controller
{
public:
	std::vector <Customer> s_customer; // This will hold all the customers in the program
	Interface UI;

public:
	Controller();
	~Controller();

	void saveCustomer();
private:
	void saveCustomerAccounts(std::fstream &myFile, Customer &customer);
	void saveCustomerTransactions(std::fstream &myFile, Account &account);
	
	/*
	Methods go here
	*/
public:
	bool login(Customer * ptr);
	void loadCustomers();

	/*
	private methods
	*/
private:
	std::vector<Account> loadAccts(std::fstream &myFile, int arr_length);
	std::vector<Transaction> loadAcctsTransactions(std::fstream & myFile, int stackLength);
};

