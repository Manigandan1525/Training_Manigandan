#pragma once
#include "Request.h"
#include<string>
#include<vector>
class Queue
{
private:
	vector<Request> queue;
	Request Req;
public:
	Queue();
	~Queue();;
	void push(Request);
	void pop();
	void display();
	bool empty();
};

