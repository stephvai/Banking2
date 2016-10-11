#include "stdafx.h"
#include "Account.h"


Account::Account()
{
}

Account::Account(int account_num, Type type, double balance):m_act_num{account_num}, m_act_type{type}, m_balance{balance}
{
}


Account::~Account()
{
}


void Account::withdraw(double amount)
{
	using namespace std;
	Interface UI;

	switch (m_act_type)
	{
	case Type::Chequing:
		withdrawCHQ(amount);
		break;
	case Type::Saving:
		withdrawSVG(amount);
		break;
	default:
		UI.error();
		break;
	}
}

void Account::deposit(double amount)
{
	Transaction transaction(amount, DR_CR::CR, Code::DEPOSIT);
	m_transactions.push_back(transaction);
	setBalance(getBalance() + amount);
}

void Account::transfer(double amount, int act_num)
{

}

double Account::getBalance()
{
	return m_balance;
}

void Account::setBalance(double amount)
{
	m_balance = amount;
}

double Account::getActNum()
{
	return m_act_num;
}




/*
private helper methods
*/

void Account::withdrawCHQ(double amount)
{
	Interface UI;


	if (getBalance() >= 1000 && (getBalance() - amount) < 1000) {
		
		/*
		Charge the fee and reccord the transaction
		*/
		bool charge = UI.fee();

			if (charge) {

				setBalance(getBalance() - 2);
				Transaction transaction(2, DR_CR::DR, Code::FEE);
				m_transactions.push_back(transaction);

				/*
				Complete the withdraw
				*/
				setBalance(getBalance() - amount);
				Transaction transaction2(amount, DR_CR::DR, Code::WITHDRAW);
				m_transactions.push_back(transaction2);
			}
		return;
	}
	/*
	If there is enough money in the account and it doesn't hit the treshhold
	*/
	else if (getBalance() - amount > 0) {
		setBalance(getBalance() - amount);
		Transaction transaction(amount, DR_CR::DR, Code::WITHDRAW);
		m_transactions.push_back(transaction);
		return;
	}
	else {
		UI.error();
	}

}

void Account::withdrawSVG(double amount)
{
	Interface UI;

	if (getBalance() - amount > 0) {
		setBalance(getBalance() - amount);
		Transaction transaction(amount, DR_CR::DR, Code::WITHDRAW);
		m_transactions.push_back(transaction);
		return;
	}
	else {
		UI.error();
	}
}
