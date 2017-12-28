#pragma once
#include "Request.h"		// insert request class
#include<string>
#include<vector>			// using vector to create vector variable
class Queue
{
private:
	vector<Request> queue;

public:
	Queue();
	~Queue();
	void push(Request);
	Request pop();
	bool empty();
	void display();

};

