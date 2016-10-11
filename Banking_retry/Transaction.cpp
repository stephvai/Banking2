#include "stdafx.h"
#include "Transactions.h"


Transaction::Transaction()
{
}

Transaction::Transaction(double amount, DR_CR dr_cr, Code code):m_amount{amount}, m_code{code}, m_dr_cr{dr_cr}
{
	/*
	get today's date:
	from http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	*/

/*	time_t t = time(0); 
	struct tm * now = localtime(&t);
	m_date = (now->tm_year + 1900) + '/'
		+ (now->tm_mon + 1) + '/'
		+ now->tm_mday;

		*/
	m_date = "hello";
}

Transaction::Transaction(double amount, DR_CR dr_cr, Code code, std::string date) :m_amount{ amount }, m_code{ code }, m_dr_cr{ dr_cr }, m_date{date}
{
}


Transaction::~Transaction()
{
}
