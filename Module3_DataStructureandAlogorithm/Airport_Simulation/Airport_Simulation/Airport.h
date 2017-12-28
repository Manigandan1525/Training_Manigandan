#pragma once
#include "Plane.h"
#include "Request.h"
#include "Queue.h"
#include<vector>
#include<future> 
class Airport
{
private:
	bool runway1 = 0;
	bool runway2 = 0;
	vector<Plane> plane_list;
	Queue landing;
	Queue takeoff;
	vector<Request> Landing;
	vector<Request> take_off;
	int landing_count=0;
	int takeoff_count=0;
	float average_landingtime = 0;
	float average_takeofftime = 0;
	int total_landing_starttime = 0;
	int total_landing_endtime = 0;
	int total_takeoff_starttime = 0;
	int total_takeoff_endtime = 0;
	int request_count = 0;
	int landing_check1 = 0, landing_check2 = 0;
	int takeoff_check1 = 0, takeoff_check2 = 0;

public:
	Airport();
	~Airport();
	void setplanedetails();
	int generate_request(int,int);
	void requestdetails();
	void landing_request();
	void takeoff_request();
	int check_runway(int, int, int);
	void display();
	void average_waitingtime();
	

};

