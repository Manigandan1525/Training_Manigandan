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
	vector<employee> emp_status;
	
	
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
	bool isEmpty();
	bool isFull();
	//string push();
	string pop();
	bool name_validation(string);
	bool gender_validation(string);
	bool age_validation(int);
	bool year_validation(int);
	bool status_validation(string);
	string print();
};

#endif