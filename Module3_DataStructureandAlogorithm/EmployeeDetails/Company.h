#ifndef Company_HEADER
#define Company_HEADER
#include"employee.h"
#include<vector>
#include<queue>
#pragma once
class Company
{
private:
	vector<employee> empname;
	queue<employee> emp_Status;
	
	
public:
	Company();
	~Company();
	void createDEtails();
	void year();
	void Highest_Pay();
	void display(int);
	void display();
	string Update_pay();
	int Search(int);
	string employee_status();
};

#endif