#pragma once
#include "Plane.h"
#include "Request.h"
#include "Queue.h"
#include<vector>
#include<future>
#include<ctime> 
#include<thread>
#include<string>
class Airport
{
	bool runway1 = 0;
	bool runway2 = 0;
	
	Plane plane;
	Request request;
	vector<Plane> aeroplane;
	vector<Request> req;
	Queue landing;
	Queue takeoff;
	vector<Request> Landing;
	vector<Request> take_off;
	int landing_count=0;
	int takeoff_count=0;
	float average_waitingtime = 0;
	int total_starttime = 0;
	int total_endtime = 0;
	int landing_requestcount = 0;
	int takeoff_requestcount = 0;
	int landing_check1 = 0, landing_check2 = 0;
	int takeoff_check1 = 0, takeoff_check2 = 0;

public:
	Airport();
	~Airport();
	void setplanedetails();
	int generate_request(int);
	void check_request();
	void requestdetails();
	void landing_request();
	void takeoff_request();
	int check_runway(int);
	void display();
	

};

