#include "stdafx.h"
#include "Transactions.h"

Transaction::Transaction()
{
}

Transaction::Transaction(double amount, DR_CR dr_cr, Code code):m_amount{amount}, m_code{code}, m_dr_cr{dr_cr}
{
	/*
	code for today date is:  http://www.cplusplus.com/reference/ctime/strftime/
	*/
	using namespace std;
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%D",timeinfo);

  m_date= string(buffer);

}

Transaction::Transaction(double amount, DR_CR dr_cr, Code code, std::string date) :m_amount{ amount }, m_code{ code }, m_dr_cr{ dr_cr }, m_date{date}
{
}


Transaction::~Transaction()
{
}
