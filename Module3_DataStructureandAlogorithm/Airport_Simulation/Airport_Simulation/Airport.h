#pragma once
#include "Plane.h"
#include "Request.h"
#include "Queue.h"
#include<vector>
#include<time.h>
#include<string>
class Airport
{
	bool runway1=0;
	bool runway2=0;
	
	Plane plane;
	Request request;
	vector<Plane> aeroplane;
	vector<Request> req;
	Queue landing;
	Queue takeoff;
	vector<Request> Landing;
	vector<Request> take_off;
	int landing_count;
	int start_time = 0;
	int end_time=0;
	int landing_completed = -1;
	int takeoff_completed = -1;
	
public:
	Airport();
	~Airport();
	void setplanedetails();
	int generate_request(int);
	void check_request();
	void requestdetails();
	void landing_request();
	void takeoff_request();
	void Landing_plane();
	void check_runway();

};

