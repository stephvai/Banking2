#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
	s_customer.reserve(100);
}


Controller::~Controller()
{
}





void Controller::openAccount() {
	using namespace std;
	string option = UI.customerOpenAccount();

	if (option == "C") {
		workingOn->openChequing();
	}
	else if (option == "S") {
		workingOn->openSavings();
	}

	UI.backToLogin();
	return initialCustomerScreen();

}

void Controller::whatUItoDisplay()
{
	using namespace std;


	switch (user->getPermission())
	{
	case Permission::MANAGER:
		return managerLoggedInScreen();
		break;
	case Permission::CUSTOMER:
		return customerLoggedInScreen();
		break;
	case Permission::MAINTENANCE:
		//return maintenanceLoggedInScreen();
		break;
	default:
		cout << "Error : no permissions are set for this username" << endl;
		//return 100;
		break;
	}
}

void Controller::managerLoggedInScreen() {
	int option = UI.managerLoggedInScreen();

	switch (option) {
	case 1: return managerNewCustomer();
	case 2: return managerExistingCustomer();
	};

}

void Controller::managerExistingCustomer() {
	using namespace std;
	string username;
	username = UI.existingCustomer();

	bool found = false;
	Customer *client = nullptr;
	for (int i = 0; i < s_customer.size() && !found; ++i) {
		client = &s_customer[i];
		if (client->getUsername() == username) {
			workingOn = &s_customer[i];
			found = true;
		}
	}

	if (found) {
		return initialCustomerScreen();
	}
	else {
		cout << "that was an invalid user name" << endl;
		client == nullptr; // return pointer to null
		return whatUItoDisplay(); // call the function recursivelly
	}


}

void Controller::managerNewCustomer() {
	using namespace std;

	cout << "Turn the screen to the client" << endl;
	string username;
	bool duplicate;

	do {
		duplicate = false;
		username = UI.createCustomerLogin();


		for (int i = 0; i < s_customer.size(); ++i) {
			if (s_customer[i].getUsername() == username) {
				duplicate = true;
			}
		}

	} while (duplicate);

	string password;
	cout << "Password: ";
	cin >> password;

	Customer  c_temp(username, password, Permission::CUSTOMER);
	s_customer.push_back(c_temp);
	workingOn = &s_customer[s_customer.size() - 1];

	return initialCustomerScreen();
}

void Controller::managerCustomerScreen()
{
}

void Controller::initialCustomerScreen()
{
	switch (user->getPermission()) {
	case Permission::CUSTOMER: return customerLoggedInScreen();
	case Permission::MANAGER: return managerCustomerLoggedInScreen();
	}
}






void Controller::customerLoggedInScreen() {
	int option =UI.customerLoggedInScreen();

	switch (option) {
	case 1: return openAccount();
	case 2: return viewAccounts();
	case 3: return viewLoans();
	case 4: return logOut();
	}


}
void Controller::managerCustomerLoggedInScreen()
{
	int option = UI.managerCustomerLoggedInScreen();
	switch (option) {
	case 1: return openAccount();
	case 2: return viewAccounts();
	case 3: return Loans();
	case 4: return whatUItoDisplay();
	}
}




void Controller::viewLoans()
{
	using namespace std;
	int option = UI.displayLoans(workingOn->loan);

	if (option == 1) {
		return initialCustomerScreen();
	}
	else {
		UI.backToLogin();

		return doTransactionOnLoan();

	}
}
void Controller::Loans()
{
	using namespace std;

	if (workingOn->loan == nullptr) {

		string input = UI.openLoan();

		if (input == "Y") {
			double amount = UI.amountOfLoan();
			cout << "To which account?: " << endl;
			UI.backToLogin();
			bool noAccount =UI.viewAccounts(workingOn);

			if (noAccount) {
				return initialCustomerScreen();
			}


			int account = UI.selectAnAccount(workingOn);

			workingOn->openLoan(workingOn->m_arr_acct[account], amount);
			return initialCustomerScreen();
		}
		else {
			cout << "returning to previous screen" << endl;
			UI.backToLogin();
			return initialCustomerScreen();
		}
	}
	else {
		return viewLoans();
	}
	};



void Controller::logOut() {
	// reset the user to null
	workingOn = nullptr;
	user = nullptr;
	login(); // return to login screen
}

void Controller::viewAccounts() {
	using namespace std;
	bool flag;
	flag = UI.viewAccounts(workingOn); // if there are no accounts to display
	if (flag) {
		return initialCustomerScreen(); // return back to the start
	}
	int key = UI.selectAnAccount(workingOn);
	string viewOrDo = UI.viewOrDoTransactions(workingOn, key);

	//pointer to the account
	Account *ptr_account = &workingOn->m_arr_acct[key];

	if (viewOrDo == "V") {
		return viewTransactions(ptr_account);
	}
	else if (viewOrDo == "D") {
		return doTransactions(ptr_account);
	}

}

void Controller::doTransactions(Account *&account) {
	using namespace std;
	int option;
	do {
		option = UI.doTransaction();
	} while (option < 1 || option > 4);

	switch (option) {
	case 1: return makeADeposit(account);
	case 2: return withdrawMoney(account);
	case 3: return transferMoney(account);
	case 4: return closeAccount(account);
	}
}

void Controller::closeAccount(Account *&account) {
	using namespace std;

	if (account->getBalance() != 0) {
		cout << "Account must be at a zero balance before closing" << endl;
		UI.backToLogin();
		return initialCustomerScreen();
	}

	for (int i = 0; i < workingOn->m_arr_acct.size() > i; ++i) {

		if (workingOn->m_arr_acct[i].getActNum() == account->getActNum()) {
			cout << "Account number: " << workingOn->m_arr_acct[i].getActNum() << " has been closed" << endl;
			UI.backToLogin();
			workingOn->m_arr_acct.erase(workingOn->m_arr_acct.begin() + i);
		}

	}

	return initialCustomerScreen();
}

void Controller::withdrawMoney(Account *&account) {
	int amount = UI.makeWithdraw();
	account->withdraw(amount);
	std::cout << "Balance : " << account->getBalance() << std::endl;

	bool otherTransaction = UI.otherTransaction();

	if (otherTransaction) {
		return doTransactions(account);
	}
	else {
		return initialCustomerScreen();
	}
}

void Controller::transferMoney(Account *&account) {
	
	using namespace std;

	cout << "Which account do you want to transfer to: " << endl;
	int key = UI.selectAnAccount(workingOn);

	float amount = UI.howMuchToTransfer();


	//pointer to the account
	Account *other_account = &workingOn->m_arr_acct[key];

	account->transfer(other_account, amount);

	std::cout << "Balance of " <<account->getActNum() <<": " << account->getBalance() << std::endl;
	std::cout << "Balance of " << other_account->getActNum() << ": " << other_account->getBalance() << std::endl;
	UI.backToLogin();

	if (UI.otherTransaction()) {
		return doTransactions(account);
	}
	else {
		return initialCustomerScreen();
	}
}

void Controller::makeADeposit(Account *&account) {
	int amount = UI.makeADeposit();
	account->deposit(amount);
	std::cout << "Balance : " << account->getBalance() << std::endl;
	UI.backToLogin();

	bool otherTransaction = UI.otherTransaction();

	if (otherTransaction) {
		return doTransactions(account);
	}
	else {
		return initialCustomerScreen();
	}
}

void Controller::viewTransactions(Account *&account) {
	using namespace std;
	UI.viewTransactions(account);
	bool login = UI.backToLogin();

	if (login) {
		return initialCustomerScreen();
	}


}

void Controller::doTransactionOnLoan()
{
	int option = UI.doTransactionOnLoan();

	switch (option) {
	case 1: return loanPayment();
	case 2: return initialCustomerScreen();
	}
}

void Controller::loanPayment()
{
	using namespace std;
	int amount = UI.loanPayment();
	cout << "From which account? : " << endl;
	bool noAccounts = UI.viewAccounts(workingOn);

	if (noAccounts) {
		return initialCustomerScreen();
	}

	int accountNum = UI.selectAnAccount(workingOn);


	workingOn->payLoan(workingOn->m_arr_acct[accountNum],amount);

	return initialCustomerScreen();

}


void Controller::saveCustomer()
{
	using namespace std;

	fstream myFile("test.txt", fstream::out | fstream::trunc);

	while (!s_customer.empty()) {
		Customer c_temp = s_customer.front();
		s_customer.erase(s_customer.begin());
		
		myFile << c_temp.getUsername() << endl;
		myFile << c_temp.getPassword() << endl;

		//if it is a customer we wil save all the account information
		myFile << static_cast<int>(c_temp.getPermission()) << endl;

		if (c_temp.getPermission() == Permission::CUSTOMER)
		{
		saveCustomerAccounts(myFile, c_temp);
		};
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









void Controller::login()
{
	bool loggedIN = false;

	using namespace std;
	string input_password, input_username;

	//call the login screen

		UI.login(input_username, input_password);


		/*
		If the user is not a customer we will login as a manager
		*/
		for (int i = 0; i < s_customer.size(); ++i) {
			user = &s_customer[i];

			if (user->getUsername().compare(input_username) == 0 && user->getPassword().compare(input_password) == 0) {
				user_loggedIn = input_username; // store the person who is logged in

				if (user->getPermission() == Permission::CUSTOMER) {
					workingOn= &s_customer[i];
					return whatUItoDisplay();
				}
				return whatUItoDisplay();
			}
		}


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
	int next;

	std::vector<Account> stackAcct;


	fstream myFile("customer.txt", fstream::in);

	while (myFile.good())
	
	{

		myFile >> username;
		myFile >> password;
		myFile >> i_permission;
		permission = static_cast<Permission> (i_permission);

		Customer customer(username, password, permission);
		cout << i_permission;

		if (permission == Permission::CUSTOMER) {
			myFile >> num_accounts;// How many accounts
			/* The next next function will load all the accounts for the customer*/
			customer.m_arr_acct = loadAccts(myFile, num_accounts);
		}
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

		control.login();
	


}


