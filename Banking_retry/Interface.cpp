#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
}

Interface::~Interface()
{
}

void Interface::login(std::string &username, std::string &password)
{
	using namespace std;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
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
	cout << "[3] Complete a transaction" << endl;
	cout << "[4] Exit" << endl;

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
		cout << "Open a chequing or saving? [C/S] :  " << endl;
		cin >> input;
		if (input != "C" || input != "S") {
			cout << "sorry, invalid input." << endl;
		}
	} while (input != "C" || input != "S");

	return input;
}

int Interface::managerLoggedInScreen()
{
	return 0;
}

int Interface::maintenanceLoggedInScreen()
{
	return 0;
}


