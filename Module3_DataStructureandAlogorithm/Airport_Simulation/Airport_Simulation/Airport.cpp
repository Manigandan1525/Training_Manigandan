#include "Airport.h"


Airport::Airport()
{
}


Airport::~Airport()
{
}
void Airport::setplanedetails()
{
	string first = "PLANE";
	int id = rand() % 300 + 100;
	string aa = to_string(id);
	string last = "ARS";
	string ID = first + aa + last;
	for (int index = 0; index < (landing.size()+takeoff.size()); index++)
	{
		if (ID == landing[index].getplaneID() || ID == takeoff[index].getplaneID())
		{
			setplanedetails();
		}
	}
	p.setplaneID(ID);
	string company_name;
	int random_com = rand() % 2;
	if (random_com == 0)
	{
	company_name = "Air Asia";
	}
	else
	{
		company_name = "Indigo";
	}
	p.setcompany_name(company_name);
	int capacity;
	int random_cap = rand() % 2;
	if (random_cap == 0)
	{
		capacity = 150;
	}
	else
	{
		capacity = 200;
	}
	p.setcapacity(capacity);
}
int Airport::generate_request(int check)
{
	int random;
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	//info = localtime(&rawtime);
	random = rand() % 500 + 80;
	while (1)
	{
		if (rawtime == check + random)
		{
			cout << "Request Created";
			return random;
		}
	}
}

void Airport::landing_request()
{
	setplanedetails();
	landing.push_back(p);
}
void Airport::takeoff_request()
{
	setplanedetails();
	takeoff.push_back(p);
}

void Airport::check_request()
{
	
}