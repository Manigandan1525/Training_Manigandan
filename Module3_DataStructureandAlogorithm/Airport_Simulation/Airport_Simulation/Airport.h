#pragma once
#include "Plane.h"
#include "Request.h"
#include<vector>
#include<time.h>
#include<string>
class Airport
{
	bool runway1=0;
	bool runway2=0;
	
	Plane p;
	vector<Plane> landing;
	vector<Plane> takeoff;
	
public:
	Airport();
	~Airport();
	void setplanedetails();
	int generate_request(int);
	void check_request();
	void landing_request();
	void takeoff_request();
	void check_runway();

};

