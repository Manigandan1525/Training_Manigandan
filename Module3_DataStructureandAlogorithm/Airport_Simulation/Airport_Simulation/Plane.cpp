#include "Plane.h"


Plane::Plane()
{
}


Plane::~Plane()
{
}
void Plane::setplaneID(string id)
{
	this->PlaneID = id;
}
string Plane::getplaneID()
{
	return this->PlaneID;
}

void Plane::setcompany_name(string name)
{
	this->company_name = name;
}
string Plane::getcompany_name()
{
	return this->company_name;
}

void Plane::setcapacity(int capacity)
{
	this->Capacity = capacity;
}
int Plane::getcapacity()
{
	return this->Capacity;
}