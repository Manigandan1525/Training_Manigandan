#ifndef Company_HEADER
#define Company_HEADER
#include"employee.h"
#include "queue_concept.h"
#include<vector>

#pragma once
class Company
{
private:
	vector<employee> empname;
	queue_concept queue;

public:
	Company();
	~Company();
	void createDetails();
	void emp_year();
	void Highest_Pay();
	void display(int);
	void display();
	void Update_pay();
	int Search(string);
	int employee_status();
	void print();
	void new_status();
	float validation(int, float);
	bool name_validation(string);
	bool gender_validation(string);
	bool age_validation(int);
	bool year_validation(int);
	bool month_validation(int);
	long long num_validation(long long);
	bool date_validation(int,int,int);
	bool numberValidation(long long);
};

#endif