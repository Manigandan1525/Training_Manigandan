#include "Queue.h"

Queue::Queue()
{
}
Queue::~Queue()
{
}

void Queue::push(Request Req)		// perform push operation
{
	queue.push_back(Req);			// push the details in queue
}

Request Queue::pop()					// perform pop operation
{

	Request req;
	req = queue[0];
	queue.erase(queue.begin());		// pop the details in queue
	return req;
}

bool Queue::empty()
{
	if (queue.empty())				// check whether queue is empty
		return true;
	else
		return false;
}

void Queue::display()				//display queue details
{
	for (int index = 0; index < queue.size(); index++)
	{
		cout <<" Plane ID: "<< '\t' << queue[index].getID()<<endl;
		cout << " Request_type: "<< '\t' << queue[index].getrequest_type()<<endl;
	}
}

