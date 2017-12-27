#include "Queue.h"

Queue::Queue()
{
}
Queue::~Queue()
{
}

void Queue::push(Request Req)
{
	queue.push_back(Req);
}

void Queue::pop()
{
		queue.erase(queue.begin());
	
}

void Queue::display()
{
	for (int index = 0; index < queue.size(); index++)
	{
		cout <<" Plane ID: "<< '\t' << queue[index].getID()<<endl;
		cout << " Request_type: "<< '\t' << queue[index].getrequest_type()<<endl;
	}
}
bool Queue::empty()
{
	if (queue.empty())
		return true;
	else
		return false;
}

