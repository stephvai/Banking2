#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
}


Controller::~Controller()
{
}



/////////////////////////////////////////////////////////////////////////////////////////
//					These methods will  the customers in the stack
/////////////////////////////////////////////////////////////////////////////////////////

void Controller::saveCustomer()
{
	using namespace std;

	fstream myFile("test.txt", fstream::out | fstream::trunc);

	while (!s_customer.empty()) {
		Customer c_temp = s_customer.front();
		s_customer.erase(s_customer.begin());
		
		myFile << c_temp.getUsername() << endl;
		myFile << c_temp.getPassword() << endl;
		myFile << static_cast<int>(c_temp.getPermission()) << endl;

		saveCustomerAccounts(myFile, c_temp);

	}
}

void Controller::saveCustomerAccounts(std::fstream & myFile, Customer & customer)
{
	using namespace std;

	// ptr to the stack
	vector<Account> *s_acct = &customer.m_arr_acct;

	//write the size of the array to the file
	myFile << s_acct->size() << endl;

	while (!s_acct->empty()) {
		Account a_temp = s_acct->front();
		s_acct->erase(s_acct->begin());

		myFile << static_cast<int> (a_temp.m_act_type) << endl;
		myFile << a_temp.getActNum() << endl;
		myFile << a_temp.getBalance() << endl;

		saveCustomerTransactions(myFile, a_temp);

	}

}

void Controller::saveCustomerTransactions(std::fstream & myFile, Account & account)
{
	using namespace std;

	//ptr to the stack 
	vector<Transaction> *s_transaction = &account.m_transactions;

	//write the number of transactions
	myFile << s_transaction->size() << endl;

	while (!s_transaction->empty()) {
		Transaction t_temp = s_transaction->front();
		s_transaction->erase(s_transaction->begin());

		myFile << t_temp.m_amount << endl;
		myFile << static_cast<int> (t_temp.m_dr_cr) << endl;
		myFile << static_cast<int> (t_temp.m_code) << endl;
		myFile << t_temp.m_date << endl;

	}


}









bool Controller::login(Customer *ptr)
{
	using namespace std;
	string input_password, input_username;

	//call the login screen
	UI.login(input_username, input_password);
	

	for (int i = 0; i < s_customer.size(); ++i) {
		ptr = &s_customer[i];
		if (ptr->getUsername().compare(input_username) == 0 && ptr->getPassword().compare(input_password) == 0) {
			return true;
		}
	}
	return false;

}

/////////////////////////////////////////////////////////////////////////////////////////
//					These methods will load the customers in the stack
/////////////////////////////////////////////////////////////////////////////////////////
void Controller::loadCustomers()
{
	using namespace std;
	string username;
	string password;
	int i_permission;
	Permission permission;
	int num_accounts;

	std::vector<Account> stackAcct;


	fstream myFile("customer.txt", fstream::in);

	while (myFile.good())
	
	{

		myFile >> username;
		myFile >> password;
		myFile >> i_permission;
		permission = static_cast<Permission> (i_permission);
		myFile >> num_accounts;// How many accounts

		Customer customer(username, password, permission);
		/* The next next function will load all the accounts for the customer*/
		customer.m_arr_acct = loadAccts(myFile, num_accounts);
		s_customer.push_back(customer); // push the customer
	}

	myFile.close();

}

std::vector<Account> Controller::loadAccts(std::fstream & myFile, int arr_length)
{
	int i_act_type;
	Type act_type;
	int act_num;
	double balance;
	std::vector<Account> s_accts;


	for (int i = 0; i < arr_length; i++) {
		myFile >> i_act_type;
		act_type = static_cast<Type> (i_act_type);
		myFile >> act_num;
		myFile >> balance;

		// Create the object
		Account account(act_num, act_type, balance);

		int arr_transactions_length;
		//Find how many transactions
		myFile >> arr_transactions_length;

		// add the transactions to the account
		account.m_transactions = loadAcctsTransactions(myFile, arr_transactions_length);

		//push it onto the stack
		s_accts.push_back(account);
	
	}

	return s_accts;
}

std::vector<Transaction> Controller::loadAcctsTransactions(std::fstream & myFile,  int stackLength)
{
	using namespace std;

	double amount;

	int i_dr_cr;
	DR_CR dr_cr;

	int i_code;
	Code code;
	string date;

	std::vector<Transaction> s_transactions;

	for (int i = 0; i < stackLength; i++) {
		myFile >> amount;

		myFile >> i_dr_cr;
		dr_cr = static_cast<DR_CR>(i_dr_cr);

		myFile >> i_code;
		code = static_cast<Code> (i_code);

		myFile >> date;

		//Create the object and push it onto the stack
		Transaction transaction(amount, dr_cr, code, date);
		s_transactions.push_back(transaction);
	}
	return s_transactions;
}
/////////////////////////////////////////////////////////////////////////////////////////

int main() {
	using namespace std;
	Controller control;
	control.loadCustomers();

	bool loggedIn = false;

	/*
	Try to log in the program
	*/

	Customer *user=nullptr; // this is a pointer to the found user

	do {
		loggedIn = control.login(user);
	} while (!loggedIn);

	Permission p_status = user->getPermission();



}


