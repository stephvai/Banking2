#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
}


Interface::~Interface()
{
}

bool Interface::fee()
{
	using namespace std;
	string answer;

	do {
		cout << "This transaction will charge a 2$ fee, do you want to continue? [Y/N]: ";
		cin >> answer;
	} while (answer != "Y" || answer != "N");

	if (answer == "Y") {
		return true;
	}
	else {
		return false;
	}

	}

void Interface::error()
{
	using namespace std;
	cout << "something went wrong" << endl;
}
