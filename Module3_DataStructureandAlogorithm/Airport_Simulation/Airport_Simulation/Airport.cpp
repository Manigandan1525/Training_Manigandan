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
	string last = "FLY";
	string ID = first + aa + last;
	for (int index = 0; index < (aeroplane.size()); index++)
	{
		if (ID == aeroplane[index].getplaneID() || ID == aeroplane[index].getplaneID())
		{
			setplanedetails();
		}
	}
	plane.setplaneID(ID);
	

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
	plane.setcompany_name(company_name);
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
	plane.setcapacity(capacity);
	aeroplane.push_back(plane);
}
int Airport::generate_request(int check)
{
	int random,a;
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	//info = localtime(&rawtime);
	random = rand() % 500 + 80;
	srand(time(NULL));
	cout << check << endl;
	cin >> a;
	system("cls");
	while (1)
	{
		time_t rawtime;
		struct tm *info;
		time(&rawtime);
		if (rawtime == (check + 5))
		{
			setplanedetails();
			cout << plane.getplaneID() << endl;
			start_time = rawtime;
			cout << "Request Created"<<endl;
			return random;
		}
	}
}

void Airport::requestdetails()
{
	request.setID(plane.getplaneID());
	cout << request.getID()<<endl;
	request.setrequest_time(start_time);
	cout << request.getrequest_time()<<endl;

}

void Airport::landing_request()
{
	requestdetails();
	request.setrequest_type("Landing");
	cout << request.getrequest_type()<<endl;
	req.push_back(request);
	Landing.push_back(request);

	//landing_count++;
}

void Airport::takeoff_request()
{
	requestdetails();
	request.setrequest_type("Takeoff");
	cout << request.getrequest_type()<<endl;
	req.push_back(request);
	take_off.push_back(request);
}

void Airport::Landing_plane()
{

}
void Airport::check_runway()
{
	int check;
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	check = rawtime;
	//cout << Landing[landing_completed].getrequest_type();
	if (landing_completed!=-1 && Landing[landing_completed].getrequest_type() == "Landing")
	{
		if (runway1 == 0)
		{
			runway1 = 1;
			while (1)
			{

				time_t rawtime;
				struct tm *info;
				time(&rawtime);
				if (rawtime == (check + 900))
				{
					runway1 = 0;
					landing_completed++;
					break;
				}
			}
		}
		else if (runway2 == 0)
		{
			runway2 = 1;
			while (1)
			{

				time_t rawtime;
				struct tm *info;
				time(&rawtime);
				if (rawtime == (check + 900))
				{
					runway2 = 0;
					landing_completed++;
					break;
				}
			}
		}
		else
		{
			landing.push(Landing[landing_completed]);
		}
		if (take_off[takeoff_completed].getrequest_type() == "Takeoff")
		{

			if (runway1 == 0)
			{
				runway1 = 1;
				while (1)
				{

					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					if (rawtime == (check + 900))
					{
						runway1 = 0;
						takeoff_completed++;
						break;
					}
				}
			}
			else if (runway2 == 0)
			{
				runway2 = 1;
				while (1)
				{

					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					if (rawtime == (check + 900))
					{
						runway2 = 0;
						takeoff_completed++;
						break;
					}
				}
			}
			else
			{
				takeoff.push(take_off[takeoff_completed]);
			}
		}
	}
}