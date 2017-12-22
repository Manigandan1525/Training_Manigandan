#pragma once
#include "Request.h"
#include<string>
#include<vector>
class Queue
{
private:
	int front = -1, rear = -1;
	vector<Request> queue;
	Request R;
public:
	Queue();
	~Queue();;
	void push(Request);
	void pop();
	void display();
};

