#include "Airport.h"
#pragma warning(disable: 4996)
Plane plane;
Request request;
Airport::Airport()
{
}

Airport::~Airport()
{
}

void Airport::setplanedetails()			// set plane details
{
	string first = "PLANE";
	int id = rand() % 300 + 100;
	string aa = to_string(id);
	string last = "FLY";
	string ID = first + aa + last;
	for (int index = 0; index < plane_list.size(); index++)
	{
		if (ID == plane_list[index].getplaneID())
		{
			setplanedetails();
		}
	}
	plane.setplaneID(ID);
	string company_name;
	int random_com = rand() % 2;
	srand(time(NULL));
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
	plane_list.push_back(plane);
}

int Airport::generate_request(int check,int simulation_time)		// generate request randomly
{
	int random=0,check_time=0;
	time_t rawtime;
	time(&rawtime);
	check_time = rawtime;
	random = rand() % 30 + 5;
	srand(time(NULL));
	while (1)
	{
		time_t rawtime;
		struct tm *info;
		time(&rawtime);
		info = localtime(&rawtime);
		if (rawtime == (check_time + random))
		{
			setplanedetails();
			request.setrequest_time(rawtime);
			cout <<"\n"<< "*********************************************************" << endl;
			cout << "Request Created"<<endl;
			cout << info->tm_hour << ":" << info->tm_min << ":" << info->tm_sec << endl;
			return random;
		}
		else if (rawtime > (check + simulation_time))
		{
			return -1;
		}
	}
}


void Airport::landing_request()
{
	request.setID(plane.getplaneID());
	cout << "Plane ID: " << '\t' << request.getID() << endl;
	request.setrequest_type("Landing");
	cout << "Request type: " << '\t'<< request.getrequest_type() << endl;
	cout << "*********************************************************" << endl;
	landing.push(request); 
	request_count++;
}

void Airport::takeoff_request()
{
	request.setID(plane.getplaneID());
	cout << "Plane ID: " << '\t' << request.getID() << endl;
	request.setrequest_type("Takeoff");
	cout << "Request type: " << '\t' << request.getrequest_type() << endl;
	cout << "*********************************************************" << endl;
	takeoff.push(request);
	request_count++;
}

int Airport::check_runway(int new_check, int simulation_time, int runway_time)
{
	if (!landing.empty())			// check whether landing queue is not empty
	{
		if (runway1 == 0)			// check runway1 is free
		{
			runway1 = 1;
			time_t rawtime;
			time(&rawtime);
			landing_check1 = rawtime;
			if (new_check + (simulation_time - runway_time) > rawtime)
			{
				Landing.push_back(landing.pop());
				Landing[landing_count].setclear_time(rawtime);
				landing_count++;
			}
			return 0;
		}
		else if (runway2 == 0)			// check runway2 is free
		{
			runway2 = 1;
			time_t rawtime;
			time(&rawtime);
			landing_check2 = rawtime;
			if (new_check + (simulation_time - runway_time) > rawtime)
			{
				Landing.push_back(landing.pop());
				Landing[landing_count].setclear_time(rawtime);
				landing_count++;
			}
			return 0;
		}
	}
	else if (!takeoff.empty())			// check whether takeoff queue is not empty
	{
		if (runway1 == 0)				// check runway1 is free
		{
			runway1 = 1;
			time_t rawtime;
			time(&rawtime);
			takeoff_check1 = rawtime;
			if (new_check + (simulation_time - runway_time) > rawtime)
				{
					take_off.push_back(takeoff.pop());
					take_off[takeoff_count].setclear_time(rawtime);
					takeoff_count++;
				}
				return 0;
			}
			else if (runway2 == 0)				// check runway2 is free
			{
				runway2 = 1;
				time_t rawtime;
				time(&rawtime);
				takeoff_check2 = rawtime;
				if (new_check + (simulation_time - runway_time) > rawtime)
				{
					take_off.push_back(takeoff.pop());
					take_off[takeoff_count].setclear_time(rawtime);
					takeoff_count++;
				}
				return 0;
			}
	}
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	if ((landing_check1 + runway_time) == rawtime)
	{
		landing_check1 = 0;
		runway1 = 0;
		return 0;
	}
	else if ((takeoff_check1 + runway_time) == rawtime)
	{
		takeoff_check1 = 0;
		runway1 = 0;
		return 0;
	}
	if ((landing_check2 + runway_time) == rawtime)
	{
		landing_check2 = 0;
		runway2 = 0;
		return 0;
	}
	else if ((takeoff_check2 + runway_time) == rawtime)
	{
	
		takeoff_check2 = 0;
		runway2 = 0;
		return 0;
	}
	return 0;
}

void Airport::display()
{
	cout << " Total request count is: " << request_count << endl;
	cout << " Waiting request:" << endl;
	landing.display();
	takeoff.display();
	average_waitingtime();
}

void Airport::average_waitingtime()
{
	for (int index = 0; index < landing_count; index++)
	{
		total_landing_starttime = total_landing_starttime + Landing[index].getrequest_time();
		total_landing_endtime = total_landing_endtime + Landing[index].getclear_time();
	}
	for (int index = 0; index < takeoff_count; index++)
	{
		total_takeoff_starttime = total_takeoff_starttime + take_off[index].getrequest_time();
		total_takeoff_endtime = total_takeoff_endtime + take_off[index].getclear_time();
	}
	total_landing_endtime = total_landing_endtime - total_landing_starttime;
	total_takeoff_endtime = total_takeoff_endtime - total_takeoff_starttime;
	cout << '\n' << " Total Landing completed: " << landing_count << endl;		// display the total landing complete
	cout << " Total Takeoff completed: " << takeoff_count << endl;					// display total takeoff complete
	average_landingtime = (float)total_landing_endtime / landing_count;					// calculate the average waiting time
	average_takeofftime = (float)total_takeoff_endtime / takeoff_count;
	cout << " The Average waiting time of Landing queue is: " << average_landingtime << " sec" << endl;
	cout << " The Average waiting time of takeoff queue is: " << average_takeofftime << " sec" << endl;
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

*/



/*for (int index = 0; index < landing_count; index++)
	{
		cout << "start time: " << Landing[index].getrequest_time() << endl;
		cout << "end time: " << Landing[index].getclear_time() << endl;
		total_starttime = total_starttime + Landing[index].getrequest_time();
		total_endtime = total_endtime + Landing[index].getclear_time();
	}
	for (int index = 0; index < takeoff_count; index++)
	{
		cout << "start time: " << take_off[index].getrequest_time() << endl;
		cout << "end time: " << take_off[index].getclear_time() << endl;
		total_starttime = total_starttime + take_off[index].getrequest_time();
		total_endtime = total_endtime + take_off[index].getclear_time();
	}
	*/












/*void Airport::check_runway1( )
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
	*/