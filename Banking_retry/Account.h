#include "Transactions.h"
#pragma once

enum class Type
{
	Chequing,
	Saving
};

class Account
{
public:

	std::vector<Transaction> m_transactions;

	/*
	Contructors
	*/
	Account();
	Account(int, Type, double);
	~Account();
	/*
	Methods
	*/
	void withdraw(double amount);
	void deposit(double amount);
	void transfer(double amount, int act_num );

	/*
	Getter / Setter
	*/
	double getBalance();
	void setBalance(double amount);
	double getActNum();


	/*
	Instance variables
	*/
	Type m_act_type;
private:
	int m_act_num;
	double m_balance;


	/*
	private methods
	*/

	void withdrawCHQ(double amount);
	void withdrawSVG(double amount);
	bool fee();
};

