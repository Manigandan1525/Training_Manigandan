#include "Airport.h"

int main()
{
	Airport airport;
	int process_timing = 15;
	int total_time;
	int check=0;
	time_t rawtime;
	//check = rawtime;
	int ran=airport.generate_request(check);
	if (ran % 2 == 0)
	{
		airport.landing_request();
	}
	else
	{
		airport.takeoff_request();
	}
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}