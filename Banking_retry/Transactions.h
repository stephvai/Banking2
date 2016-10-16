#pragma once

enum class DR_CR
{
	DR,
	CR
};

enum class Code
{
	FEE,
	WITHDRAW,
	DEPOSIT,
	TRANSFER
};

class Transaction
{
public:
	double m_amount;
	DR_CR m_dr_cr;
	Code m_code;
	std::string m_date;

public:
	Transaction();
	Transaction(double amount, DR_CR dr_cr, Code code);
	Transaction(double amount, DR_CR dr_cr, Code code, std::string date);
	~Transaction();

};

