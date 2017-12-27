#include "Airport.h"
#pragma warning(disable: 4996)

Airport airport;

void request_generate(int check)
{
	int ran = 0;
	while (1)
		{
			time_t rawtime;
			struct tm *info;
			time(&rawtime);
			info = localtime(&rawtime);
			if ((check + 120) >= rawtime)
			{
				ran = airport.generate_request(check);
				if (ran == -1)
				{
					airport.display();
					break;
				}
				else
				{
					if (ran % 2 == 0)
					{
						
						airport.landing_request();
					}
					else
					{
						
						airport.takeoff_request();
					}
					
				}
			}
		}
}

void allocate_runway(int check)
{
	while (1)
	{
			time_t rawtime;
			struct tm *info;
			time(&rawtime);
			info = localtime(&rawtime);
			if ((check + 120) >= rawtime)
			{
				airport.check_runway(check);			}
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
	check = rawtime;
	async(request_generate, check);
	async(allocate_runway, check);
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}

