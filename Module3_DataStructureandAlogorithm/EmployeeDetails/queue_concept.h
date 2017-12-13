#pragma once
#include"employee.h"
#include<vector>
class queue_concept
{
private:
	int front = -1, rear = -1;
	vector<employee> bench;
	employee emp;
public:
	queue_concept();
	~queue_concept();
	int print();
	void push(employee);
	string pop();
};

