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
	int withdraw(double amount);
	int deposit(double amount);
	int transfer(Account *& otherAct, double amount);

	/*
	Getter / Setter
	*/
	double getBalance();
	void setBalance(double amount);
	int getActNum();


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

	int withdrawCHQ(double amount);
	int withdrawSVG(double amount);
	bool fee();
};

