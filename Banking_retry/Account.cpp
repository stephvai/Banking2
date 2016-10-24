#include "stdafx.h"
#include "Account.h"


/*

*/
int Account::s_accountNum;

Account::Account()
{
}

Account::Account(Type type):m_act_type{type}
{
	m_balance = 0;
	m_act_num = ++s_accountNum;
}

Account::Account(int account_num, Type type, double balance):m_act_num{account_num}, m_act_type{type}, m_balance{balance}
{
}


Account::~Account()
{
}


int Account::withdraw(double amount)
{
	using namespace std;

	switch (m_act_type)
	{
	case Type::Chequing:
		return withdrawCHQ(amount);
		break;
	case Type::Saving:
		return withdrawSVG(amount);
		break;
	default:
		cout << "something went wrong " << endl;
		break;
	}
}

int Account::deposit(double amount)
{
	Transaction transaction(amount, DR_CR::CR, Code::DEPOSIT);
	m_transactions.push_back(transaction);
	setBalance(getBalance() + amount);
	return 0;
}

int Account::transfer(Account *&otherAct, double amount)
{
	using namespace std;
	if (getActNum() != otherAct->getActNum()) {
		int failure = withdraw(amount);
		if (!failure) {
			otherAct->deposit(amount);
			return 0;
		}
	}
	else {
		cout << "You cannot transfer to the same account" << endl;
		return 1;
	}
}

double Account::getBalance()
{
	return m_balance;
}

void Account::setBalance(double amount)
{
	m_balance = amount;
}

int Account::getActNum()
{
	return m_act_num;
}




/*
private helper methods
*/

int Account::withdrawCHQ(double amount)
{


	if (getBalance() >= 1000 && (getBalance() - amount) < 1000 && (getBalance()-amount) > 0) {
		
		/*
		Charge the fee and reccord the transaction
		*/
		bool charge = fee();

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
				return 0;
			}
	}
	/*
	If there is enough money in the account and it doesn't hit the treshhold
	*/
	else if (getBalance() - amount > 0) {
		setBalance(getBalance() - amount);
		Transaction transaction(amount, DR_CR::DR, Code::WITHDRAW);
		m_transactions.push_back(transaction);
		return 0;
	}
	else {
		std::cout << "Your balance must be greater than 0" << std::endl;
		return 1;
	}

}

int Account::withdrawSVG(double amount)
{
	using namespace std;

	if (getBalance() - amount > 0) {
		setBalance(getBalance() - amount);
		Transaction transaction(amount, DR_CR::DR, Code::WITHDRAW);
		m_transactions.push_back(transaction);
		return 0;
	}
	else {
		cout << "Your balance must be greater than 0" << endl;
		return 1;
	}
}


bool Account::fee()
{
	using namespace std;
	string answer;

	do {
		cout << "This transaction will charge a 2$ fee, do you want to continue? [Y/N]: ";
		cin >> answer;
	} while (answer != "Y" && answer != "N");

	if (answer == "Y") {
		return true;
	}
	else {
		return false;
	}

}
