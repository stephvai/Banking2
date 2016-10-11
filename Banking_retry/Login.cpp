#include "stdafx.h"
#include "Login.h"


Login::Login(std::string username, std::string password, Permission permission):m_password{password}, m_username{username}, m_permission{permission}
{
}


Login::~Login()
{
}

std::string Login::getUsername()
{
	return m_username;
}

std::string Login::getPassword()
{
	return m_password;
}

Permission Login::getPermission()
{
	return m_permission;
}
