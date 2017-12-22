#pragma once
#include "Plane.h"
#include<ctime>
class Request
{
private:
	string plane_id;
	time_t request_time;
	time_t clear_time;
	string request_type;
	
	
public:
	
	Request();
	~Request();
	void setID(string);
	string getID();
	void setrequest_time(time_t);
	time_t getrequest_time();
	void setclear_time(time_t);
	time_t getclear_time();
	void setrequest_type(string);
	string getrequest_type();
};

