#include "stdafx.h"
#include "Date.h"


Date::Date()
{
	using namespace std;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	char buffer2[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%D", timeinfo);
	m_date = string(buffer);

	strftime(buffer2, 80, "%r", timeinfo);
	m_time = buffer2;
}


Date::~Date()
{
}
