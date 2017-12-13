#include "queue_concept.h"


queue_concept::queue_concept()
{
}


queue_concept::~queue_concept()
{
}
void queue_concept::push(employee empname)
{
	rear = rear + 1;
	bench.push_back(empname);
}
string queue_concept::pop()
{
	//cout << bench.getEmp_id() << endl;
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



