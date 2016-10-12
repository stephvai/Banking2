#include "Permission.h"
#pragma once



class Interface
{
public:
	Interface();
	~Interface();
	/*
	Methods
	*/
	void login(std::string &username, std::string &password);
	int customerLoggedInScreen();
	std::string customerOpenAccount();

	int managerLoggedInScreen();
	int maintenanceLoggedInScreen();
};

