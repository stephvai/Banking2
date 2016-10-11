#include "stdafx.h"
#include "Customer.h"


Customer::Customer(std::string username, std::string password, Permission permission):Login(username, password,  permission)
{
}


Customer::~Customer()
{
}
