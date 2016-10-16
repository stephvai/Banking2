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
	Account(Type type);
	Account(int, Type, double);
	~Account();
	/*
	Methods
	*/
	void withdraw(double amount);
	void deposit(double amount);
	void transfer(Account *& otherAct, double amount);

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
	static int s_accountNum;


	/*
	private methods
	*/

	void withdrawCHQ(double amount);
	void withdrawSVG(double amount);
	bool fee();
};

