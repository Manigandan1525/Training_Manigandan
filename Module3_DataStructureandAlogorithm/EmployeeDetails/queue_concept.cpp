#include "queue_concept.h"

//employee emp;
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
int queue_concept::pop()
{

	if (front >= rear)
	{
		return 0;//cout << "Bench is empty";
	}
	else
	{
		front = front + 1;
		int id = bench[front].getEmp_id();
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




//emp_status.erase(emp_status.begin());