#include "Airport.h"
#pragma warning(disable: 4996)
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
	for (int index = 0; index < aeroplane.size(); index++)
	{
		if (ID == aeroplane[index].getplaneID())
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
	int random=0,check_time=0;
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	check_time = rawtime;
	random = rand() % 25 + 5;
	srand(time(NULL));
	//cout << check << endl;
	//cin >> a;
	//system("cls");
	while (1)
	{
		time_t rawtime;
		struct tm *info;
		time(&rawtime);
		info = localtime(&rawtime);
		if (rawtime == (check_time + random))
		{
			setplanedetails();
			//cout << plane.getplaneID() << endl;
			start_time = rawtime;
			cout << "Request Created"<<endl;
			return random;
		}
		else if (rawtime > (check + 120))
		{
			return -1;
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
	landing.push(Landing[landing_requestcount]);
	landing_requestcount++;
	//landing_count++;
}

void Airport::takeoff_request()
{
	requestdetails();
	request.setrequest_type("Takeoff");
	cout << request.getrequest_type()<<endl;
	req.push_back(request);
	take_off.push_back(request);
	takeoff.push(take_off[takeoff_requestcount]);
	takeoff_requestcount++;
}

void Airport::Landing_plane()
{

}
void Airport::check_runway1( )
{
		//cout << Landing[landing_completed].getrequest_type();
		if (!landing.empty())
		{
			if (Landing[landing_count].getrequest_type() == "Landing")
			{
				if (runway1 == 0)
				{
					cout << "Plane allocated in runway1" << endl;
					landing_count++;
					runway1 = 1;
					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					int check1 = rawtime;
					while (1)
					{
						time_t rawtime;
						struct tm *info;
						time(&rawtime);
						if (rawtime == (check1 + 35))
						{
							runway1 = 0;
							cout << "**********************complete*****************";
							landing.pop();
							break;
						}
					}
				}
		
				else
				{
					check_runway1();
				}
			}
		}
		else if (!takeoff.empty())
		{
			cout << "1";
			if (take_off[takeoff_count].getrequest_type() == "Takeoff")
			{
				cout << "1";
				if (runway1 == 0)
				{
					cout << "Plane allocated in runway1" << endl;
					takeoff_count++;
					runway1 = 1;
					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					int check1 = rawtime;
					while (1)
					{
						time_t rawtime;
						struct tm *info;
						time(&rawtime);
						if (rawtime == (check1 + 35))
						{
							runway1 = 0;
							cout << "**********************complete*****************";
							takeoff.pop();
							break;
						}
					}
				}
			
				else
				{
					check_runway1();
				}
			}
		}
	}

void Airport::check_runway2( )
{
	if (!landing.empty())
	{
		if (Landing[landing_count].getrequest_type() == "Landing")
		{
			if (runway2 == 0)
			{
				cout << "Plane allocated in runway2" << endl;
				landing_count++;
				runway2 = 1;
				time_t rawtime;
				struct tm *info;
				time(&rawtime);
				int check2 = rawtime;
				while (1)
				{
					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					if (rawtime == (check2 + 35))
					{
						runway2 = 0;
						cout << "**********************complete2*****************";
						landing.pop();
						break;
					}
				}
			}
			else
			{
				check_runway2();
			}
		}
	}
	else if (!takeoff.empty())
	{
		cout << "1";
		if (take_off[takeoff_count].getrequest_type() == "Takeoff")
		{
			if (runway2 == 0)
			{
				cout << "Plane allocated in runway2" << endl;
				takeoff_count++;
				runway2 = 1;
				time_t rawtime;
				struct tm *info;
				time(&rawtime);
				int check2 = rawtime;
				while (1)
				{

					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					if (rawtime == (check2 + 35))
					{
						runway2 = 0;
						cout << "**********************complete2*****************";
						takeoff.pop();
						break;
					}
				}
			}
			else
			{
				check_runway2();
			}
		}
	}
}

void Airport::display()
{
	cout << "The queue average waiting time: "<<endl;
	cout << "landing:" << endl;
	landing.display();
	cout << "takeoff:" << endl;
	takeoff.display();
}

/*#include "Airport.h"

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
    int random, a;
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
            cout << "Request Created" << endl;
            return random;
        }
    }
}

void Airport::requestdetails()
{
    request.setID(plane.getplaneID());
    cout << request.getID() << endl;
    request.setrequest_time(start_time);
    cout << request.getrequest_time() << endl;

}

void Airport::landing_request()
{
    requestdetails();
    request.setrequest_type("Landing");
    cout << request.getrequest_type() << endl;
    landing_completed++;
    req.push_back(request);
    Landing.push_back(request);
    if (!landing.isEmpty())
    {
        landing.push(Landing[landing_completed]);
    }

    //landing_count++;
}

void Airport::takeoff_request()
{
    requestdetails();
    request.setrequest_type("Takeoff");
    cout << request.getrequest_type() << endl;
    takeoff_completed++;
    req.push_back(request);
    take_off.push_back(request);
    if (!landing.isEmpty())
    {
        takeoff.push(take_off[takeoff_completed]);
    }
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
    if (!landing.isEmpty())
    {
        
    }
    //cout << Landing[landing_completed].getrequest_type();
    if (landing_completed != -1 && Landing[landing_completed].getrequest_type() == "Landing")
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
                    break;
                }
            }
        }
        else
        {
            landing.push(Landing[landing_completed]);
        }
    }
    else if (takeoff_completed != -1 && take_off[takeoff_completed].getrequest_type() == "Takeoff")
        {

        time_t rawtime;
        struct tm *info;
        time(&rawtime);
        check = rawtime;
        cout << check;
            if (runway1 == 0)
            {
                runway1 = 1;
                while (1)
                {

                    time_t rawtime;
                    struct tm *info;
                    time(&rawtime);
                    if (rawtime == (check + 9))
                    {
                        runway1 = 0;
                        cout << "AS";
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
*/