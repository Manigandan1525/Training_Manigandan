#include "Airport.h"			//include Airport class
#pragma warning(disable: 4996)

Airport airport;				//create object in Airport class

void request_generate(int check, int simulation_time)		//generate request randomly
{
	int ran = 0;
	while (1)
		{
			time_t rawtime;		
			time(&rawtime);
			if ((check + simulation_time) >= rawtime)			//check the time, whether the time is complete or not
			{
				ran = airport.generate_request(check, simulation_time);		//calling the generate request function
				if (ran == -1)								//-1 denotes end of simulated time interval 
				{
					airport.display();						//calling display function
					break;
				}
				else
				{
					if (ran % 2 == 0)
					{
						
						airport.landing_request();			//calling landing request function
					}
					else
					{
						
						airport.takeoff_request();			//calling takeoff request function
					}
					
				}
			}
		}
}

void allocate_runway(int check, int simulation_time, int runway_time)
{
	while (1)
	{
			time_t rawtime;
			time(&rawtime);
			if ((check + 300) >= rawtime)				//check the time, whether the time is complete or not
			{
				airport.check_runway(check, simulation_time, runway_time);			//calling check runway function
			}
			else
			{
				break;
			}
	}
}

int main()
{
	time_t rawtime;
	struct tm *info;
	time(&rawtime);
	info = localtime(&rawtime);
	cout << info->tm_hour << ":" << info->tm_min << ":" << info->tm_sec << endl;
	int check = 0;
	int simulation_time = 600;
	int runway_time = 50;
	check = rawtime;
	async(request_generate, check, simulation_time);				//call thread function
	async(allocate_runway, check, simulation_time, runway_time);				//call thread function
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}			//main
