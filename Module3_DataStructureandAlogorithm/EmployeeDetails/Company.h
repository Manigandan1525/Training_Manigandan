#ifndef Company_HEADER
#define Company_HEADER
#include"employee.h"
#include "queue_concept.h"
#include<vector>
//#include<queue>
#pragma once
class Company
{
private:
	vector<employee> empname;
	queue_concept queue;
	//vector<employee> emp_status;
	
	
public:
	Company();
	~Company();
	void createDetails();
	void year();
	void Highest_Pay();
	void display(int);
	void display();
	string Update_pay();
	int Search(int);
	string employee_status();
	void print();
	//string push();
	string pop_new();
	bool name_validation(string);
	bool gender_validation(string);
	bool age_validation(int);
	bool year_validation(int);
	bool status_validation(string);
	int CheckInput();
};

#endif