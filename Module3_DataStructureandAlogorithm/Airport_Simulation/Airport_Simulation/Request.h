#pragma once
#include "Plane.h"
#include<ctime>
class Request
{
	time_t rawtime;
	string aa;
	
public:
	Plane P;
	Request();
	~Request();
	void getdata()
	{
		P.getplaneID();
	}
};

