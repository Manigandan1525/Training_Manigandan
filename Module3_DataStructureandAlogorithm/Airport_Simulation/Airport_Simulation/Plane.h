#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Plane
{
private:
	string PlaneID;
	string company_name;
	int Capacity;
public:
	Plane();
	~Plane();
	void setplaneID(string );
	string getplaneID();
	void setcompany_name(string );
	string getcompany_name();
	void setcapacity(int );
	int getcapacity();
};

