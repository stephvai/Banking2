#pragma once

enum class Permission
{
	MANAGER,
	CUSTOMER,
	MAINTENANCE
};


class Login
{
public:
	Login(std::string username, std::string password, Permission permission);
	~Login();
	std::string getUsername();
	std::string getPassword();
	Permission getPermission();
private:
	std::string m_username;
	std::string m_password;
	Permission m_permission;



};

