#include "stdafx.h"
#include "Transactions.h"


Transaction::Transaction()
{
}

Transaction::Transaction(double amount, DR_CR dr_cr, Code code):m_amount{amount}, m_code{code}, m_dr_cr{dr_cr}
{
	using namespace std;

	time_t rawtime;
	tm timeinfo;
	errno_t result = localtime_s(&timeinfo, &rawtime);
	
	int year = timeinfo.tm_year + 1900;
	int month = timeinfo.tm_mon + 1;
	int day = timeinfo.tm_mday;

	m_date = "hello";

}

Transaction::Transaction(double amount, DR_CR dr_cr, Code code, std::string date) :m_amount{ amount }, m_code{ code }, m_dr_cr{ dr_cr }, m_date{date}
{
}


Transaction::~Transaction()
{
}
