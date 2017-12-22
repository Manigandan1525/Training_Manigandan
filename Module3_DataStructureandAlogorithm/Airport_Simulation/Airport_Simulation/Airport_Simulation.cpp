#include "Airport.h"
#include<ctime>
#pragma warning(disable: 4996)
//#include "queue_concept"
int main()
{
	Airport airport;
	int process_timing = 15;
	int total_time;
	int check=0;
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	cout << rawtime << endl;
	check = rawtime;
	cout << check << endl;
	int ran=airport.generate_request(check);
	cout << ran;
	if (ran % 2 == 0)
	{
		cout << "landing";
		airport.landing_request();
	}
	else
	{
		cout << "takeoff";
		airport.takeoff_request();
	}
	airport.check_runway();
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}