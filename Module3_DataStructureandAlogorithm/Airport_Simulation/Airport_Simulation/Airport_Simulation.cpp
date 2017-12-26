#include "Airport.h"
#include<ctime>
#include<thread>
#pragma warning(disable: 4996)
//#include "queue_concept"
	Airport airport;
//	void allocate_runway2(int);
//	void request_generate(int);
//	void allocate_runway1(int);
	
	void request_generate(int check)
	{
		int ran = 0;
		int i = 0;
		while (1)
		{
			time_t rawtime;
			struct tm *info;
			time(&rawtime);
			info = localtime(&rawtime);
			if ((check + 120) >= rawtime)
			{
				cout << ++i << "\t";
				cout << info->tm_sec << endl;
				ran = airport.generate_request(check);
				cout << ran << endl;
				if (ran == -1)
				{
					cout << "close";
					airport.display();
					break;
				}
				else
				{
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
					time_t rawtime;
					struct tm *info;
					time(&rawtime);
					info = localtime(&rawtime);
					//cout << "Raw time: " << rawtime << endl;
					//cout << "cheeck time: " << check << endl;
				}
			}

		}
	}

	void allocate_runway1(int check)
	{
		while (1)
		{
			time_t rawtime;
			struct tm *info;
			time(&rawtime);
			info = localtime(&rawtime);
			if ((check + 120) >= rawtime)
			{
				airport.check_runway1();
			}
			else
			{
				cout << "close1";
				break;
			}

		}
	}

	void allocate_runway2(int check)
	{
		cout << "qwe"<<"\t\t\t"<<"quw"<<endl;
		while (1)
		{
			time_t rawtime;
			struct tm *info;
			time(&rawtime);
			info = localtime(&rawtime);
			if ((check + 120) >= rawtime)
			{
				airport.check_runway2();
			}
			else
			{
				cout << "close2";

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
	int check = 0;
	check = rawtime;
	//thread t(request_generate, check);
	//thread t1(allocate_runway1, check);

	//thread t2(allocate_runway2, check);

	async(request_generate, check);
	async(allocate_runway1, check);
	async(allocate_runway2, check);
	cout << "aaas";
	cin.ignore(1000, '\n');
	cin.get();
	return 0;

	//async(allocate_runway2, check);
	//int process_timing = 15;
	//int total_time;
	//int check=0;
	//time_t rawtime;
	//struct tm *info;
	//time(&rawtime);
	//info = localtime(&rawtime);
	//cout << rawtime << endl;
	//check = rawtime;
	//cout << check << endl;
	
	/*int ran=airport.generate_request(check);
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
	}*/

	//airport.check_runway();
	//airport.display();

}

