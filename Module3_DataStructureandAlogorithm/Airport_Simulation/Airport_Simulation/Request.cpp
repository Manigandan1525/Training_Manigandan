#include "Request.h"
#include<string>
//Plane plane;
Request::Request()
{
	
}
Request::~Request()
{
}

void Request::setID(string id)					// set plane ID
{
	this->plane_id = id;
}
string Request::getID()							// get plane ID
{
	return this->plane_id;
}

void Request::setrequest_time(int time)			// set plane rrequest time
{
	this->request_time = time;
}
int Request::getrequest_time()					// get plane rrequest time
{
	return this->request_time;
}

void Request::setclear_time(int time)			// set plane clear time
{
	this->clear_time = time;
}
int Request::getclear_time()					// get plane clear time
{
	return this->clear_time;
}

void Request::setrequest_type(string type)		// set plane request type
{
	this->request_type = type;
}
string Request::getrequest_type()				// get plane request type
{
	return this->request_type;
}