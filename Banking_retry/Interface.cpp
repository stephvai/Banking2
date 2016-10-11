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
void Interface::loggedInScreen(Permission permission)
{
}
*/

