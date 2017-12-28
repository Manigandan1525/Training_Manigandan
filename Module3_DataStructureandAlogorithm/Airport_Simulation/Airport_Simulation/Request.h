#pragma once
#include "Plane.h"			
#include<ctime>
class Request
{
private:
	string plane_id;
	int request_time;
	int clear_time;
	string request_type;
	
public:
	Request();
	~Request();
	void setID(string);
	string getID();
	void setrequest_time(int);
	int getrequest_time();
	void setclear_time(int);
	int getclear_time();
	void setrequest_type(string);
	string getrequest_type();
};

