#include "Request.h"
#include<string>
Plane plane;
Request::Request()
{
	
}
Request::~Request()
{
}

void Request::setID(string id)
{
	this->plane_id = id;
}
string Request::getID()
{
	return this->plane_id;
}

void Request::setrequest_time(int time)
{
	this->request_time = time;
}
int Request::getrequest_time()
{
	return this->request_time;
}

void Request::setclear_time(int time)
{
	this->clear_time = time;
}
int Request::getclear_time()
{
	return this->clear_time;
}

void Request::setrequest_type(string type)
{
	this->request_type = type;
}
string Request::getrequest_type()
{
	return this->request_type;
}