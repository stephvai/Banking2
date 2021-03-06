#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
}

Interface::~Interface()
{
}


std::string Interface::existingCustomer() {
	using namespace std;
	string username;
	cout << "User name of the client you are looking for : ";
	cin >> username;
	return username;

}

int Interface::displayLoans(Loan *&loan)
{
	using namespace std;

	if (loan == nullptr) {
		cout << "No loans to display" << endl;
		return 1;
	}
	else {
		cout << "\t\t" << "principal:" << "\t\t" << "interest" << endl;
		cout << "[1] \t\t" << loan->principal << "\t\t\t" << loan->interest << endl;
		return 0;
	}
}

int Interface::doTransactionOnLoan()
{
	using namespace std;

	int input;


	do {
		cout << "[1] payment" << endl;
		cout << "[2] return to login screen" << endl;
		cout << "Enter: ";
		cin >> input;
	} while (input != 1 && input != 2);
	return input;
}

int Interface::loanPayment()
{
	using namespace std;
	int amount;

	do {
		cout << "How much do you want to pay?: ";
		cin >> amount;
	} while (amount <= 0);

	return amount;
}



int Interface::managerLoggedInScreen() {
	using namespace std;
	int input;

	cout << "[1] New client" << endl;
	cout << "[2] Existing Client" << endl;
	cout << "[3] Logout" << endl;

	do {
		cout << "Enter: ";
		cin >> input;
	} while (input < 1 || input > 3);

		return input;

}


std::string Interface::createCustomerLogin() {
	using namespace std;
	string username;
	cout << "Pick a username that doesn't exist: ";
	cin >> username;
	return username;
}

int Interface::managerCustomerLoggedInScreen()
{
	using namespace std;

	cout << "Select an option: \n" << endl;
	cout << "[1] Open an account" << endl;
	cout << "[2] View accounts" << endl;
	cout << "[3] Loans" << endl;
	cout << "[4] Add Overdraft" << endl;
	cout << "[5] Exit existing Customer" << endl;

	cout << "Enter: ";

	int input;

	do {
		cin >> input;

		/*
		Error handling
		*/
		if (input > 5 || input < 0) {
			cout << "Error: enter a valid option" << endl;
		}
	} while (input > 5 || input < 0); //invalid option

	return input;
}

std::string Interface::openLoan()
{
	using namespace std;
	string input;
	do {
		cout << "Would you like to open one? [Y/N] : ";
		cin >> input;
	} while (input != "Y" && input != "N");

	return input;
}

double Interface::amountOfLoan()
{
	using namespace std;
	double amount;

	do {
		cout << "Amount: ";
		cin >> amount;
	} while (amount <= 0);

	return amount;

}

int Interface::maintenanceLoggedInScreen(int trace)
{
	using namespace std;
	int input;

	do {
		if (trace) {
			cout << "[1] Turn trace OFF " << endl;
		}
		else {
			cout << "[1] Turn trace ON " << endl;
		}
		cout << "[2] Logout" << endl;
		
		cout << "Enter: ";
		cin >> input;

	} while (input != 1 && input != 2);

	return input;


}

int Interface::addODP()
{
	int amount;
	do {
		using namespace std;
		cout << "New ODP amount: ";
		cin >> amount;
		return amount;
	} while (amount <= 0);
}


void Interface::login(std::string &username, std::string &password)
{
	using namespace std;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
}

int Interface::doTransaction() {
	using namespace std;

	int input;

	cout << "[1] Make a deposit " << endl;
	cout << "[2] Withdraw money " << endl;
	cout << "[3] Transfer some funds " << endl;
	cout << "[4] Close the account " << endl;

	cout << "Enter: ";

	cin >> input;

	return input;
}



float Interface::makeWithdraw() {
	using namespace std;
	float input;
	do {
		cout << "How much would you like to withdraw?: ";
		cin >> input;
	} while (input <= 0);
	return input;
}

float Interface::howMuchToTransfer() {
	using namespace std;
	float input;
	do {
		cout << "How much would you like to transfer?:";
		cin >> input;
	} while (input <= 0);
	return input;
}

float Interface::makeADeposit() {
	using namespace std;
	float input;
	do {
		cout << "How much would you like to deposit?: ";
		cin >> input;
	} while (input <= 0);
	return input;
}

bool Interface::otherTransaction() {
	using namespace std;
	string input;

	do {
		cout << "Would you like to do another transaction? [Y/N] : ";
		cin >> input;
	} while (input != "Y" && input != "N");

	if (input == "Y") {
		return true;
	}else{
		return false;
	}
	return false;
}

bool Interface::viewAccounts(User *&local_user) {
	using namespace std;

	Type e_accountType;
	string s_accountType;
	int accountNum;
	float balance;
	int odp;

	if (local_user->m_arr_acct.size() == 0) {
		cout << "There is no accounts; please open one" << endl;
		return true;
	}

	cout << "key:" << "\ttype:" << "\taccount num:" << "\t\tbal:"<<"\t\todp:" << endl;

	for (int i = 0; i < local_user->m_arr_acct.size(); ++i) {

		e_accountType = local_user->m_arr_acct[i].m_act_type;
		switch (e_accountType) {
		case Type::Chequing: s_accountType = "Chq"; break;
		case Type::Saving: s_accountType = "Sav"; break;
		}

		accountNum = local_user->m_arr_acct[i].getActNum();
		balance = local_user->m_arr_acct[i].getBalance();
		odp = local_user->m_arr_acct[i].odp.m_amount;


		cout <<i <<"\t "  << s_accountType << "\t" << accountNum << "\t\t\t" << balance <<"\t\t" << odp<< endl;
	}
	return false;

}

int Interface::selectAnAccount(User *&local_user) {
	using namespace std;
	int input;
	do {
		cout << "Enter a valid account key ";
		cin >> input;
	} while (input < 0 || input >= local_user->m_arr_acct.size());

	return input;
}

std::string Interface::viewOrDoTransactions(User *&local_user, int accountKey){
	using namespace std;
	string stringInput;
	do {
		cout << "View transactions [V] or do a transaction[D] :";
		cin >> stringInput;
	} while (stringInput != "V" && stringInput != "D");
	
	return stringInput;
}

void Interface::viewTransactions(Account *&account) {
	using namespace std;
	
	double amount;
	Code e_code;
	string s_code;
	DR_CR e_dr_cr;
	string s_dr_cr;
	string date;

	//amount, s_code, s_dr_cr, date

	cout << "\namount:\t" << "code:\t" << "DR/CR:\t" << "\t\tdate:" << endl;

	Transaction *ptr_transaction = nullptr;

	for (int i = 0; i < account->m_transactions.size(); ++i) {

		// a pointer to the transaction
		ptr_transaction = &(account->m_transactions[i]);

		amount = ptr_transaction->m_amount;
		e_code = ptr_transaction->m_code;
		e_dr_cr = ptr_transaction->m_dr_cr;
		date = ptr_transaction->m_date;

		switch (e_code)
		{
		case Code::FEE: s_code = "FEE";
			break;
		case Code::WITHDRAW: s_code = "WTH";
			break;
		case Code::DEPOSIT: s_code = "DEP";
			break;
		}

		switch (e_dr_cr)
		{
		case DR_CR::DR: s_dr_cr = "DR";
			break;
		case DR_CR::CR:s_dr_cr = "CR";
			break;
		}

		//amount, s_code, s_dr_cr, date
		cout << amount << "\t" << s_code << "\t" << s_dr_cr << "\t\t\t" << date << "\n" << endl;

	}
}


bool Interface::backToLogin() {
	using namespace std;

	cout << "Press Enter to Continue.." << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	return true;
}


/*
Helper private methods
*/

int Interface::customerLoggedInScreen()
{
	using namespace std;

	cout << "Select an option: \n"<< endl;
	cout << "[1] Open an account" << endl;
	cout << "[2] View accounts" << endl;
	cout << "[3] View loans" << endl;
	cout << "[4] Logout" << endl;
	
	cout << "Enter: ";

	int input;

	do {
		cin >> input;

		/*
		Error handling
		*/
		if (input > 4 || input < 0) {
			cout << "Error: enter a valid option" << endl;
		}
	} while (input > 4 || input < 0); //invalid option

	return input;
}


std::string Interface::customerOpenAccount()
{
	using namespace std;
	string input;

	do {
		cout << "Open a chequing or saving? [C/S] :  ";
		cin >> input;
		if (input != "C" && input != "S") {
			cout << "sorry, invalid input." << endl;
		}
	} while (input != "C" && input != "S");

	return input;
}


