#include "Queue.h"

Queue::Queue()
{
}
Queue::~Queue()
{
}

void Queue::push(Request Req)
{
	//rear = rear + 1;
	queue.push_back(Req);
}

void Queue::pop()
{
		//front = front + 1;
		queue.erase(queue.begin());
	
}

void Queue::display()
{
	for (int index = 0; index < queue.size(); index++)
	{
		cout << queue[index].getID()<<endl;
		cout << queue[index].getrequest_time()<<endl;
	}
}
bool Queue::empty()
{
	if (queue.empty())
		return true;
	else
		return false;
}


/*
void queue_concept::push(employee empname)
{
	rear = rear + 1;
	bench.push_back(empname);
}
string queue_concept::pop()
{
	if (front >= rear && front == -1)
	{
		cout << "Unnecessary Entry";
		return "Empty";
	}
	else if (front >= rear)
	{
		cout << "Bench is Empty";
		return "Empty";
	}
	else
	{
		front = front + 1;
		
		string id = bench[front].getEmp_id();
				bench.erase(bench.begin());
				return id;
	}
	}


int queue_concept::print()
{
	if (front >= rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

*/