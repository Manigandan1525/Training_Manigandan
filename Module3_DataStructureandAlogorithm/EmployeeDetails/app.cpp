#include "employee.h"
#include "Company.h"
#include<iostream>
using namespace std;
int main()
{
	Company cmp;
	int option, no_of_employee, leave = 0;
	//cmp.createDEtails();
	//cmp.display();
	cout << "Enter no. of employee";
	cin >> no_of_employee;
	for (int iteration = 0; iteration < no_of_employee; iteration++)
	{
		cmp.createDEtails();
	}
	do
	{
		cout << "Enter your option" << '\n' <<'\n'<< "1. Add New Employee\n2.Display names of employee from a particular year of joining" << '\n'
			<< "3.Display all details of the employee from a particular department having the highest pay\n4.Display all details of all employees in ascending order based on emp id"
			<< '\n' <<"5.Given a particular employee id, update pay of a particular employee(Update pay by 5%)\n6.Enployee Status Project/Bench\n7.Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:cmp.createDEtails();
			   break;
		case 2:cout << "Enter the year";
			   cmp.year();
			   break;
		case 3:cout << "Enter Department";
			   cmp.Highest_Pay();
			   break;
		case 4:cout << "All Employee Details";
			   cmp.display();
		case 5:cout << "Enter employee ID:";
			   cmp.Update_pay();
		case 6:cout << "Enter employee ID:";
		
		case 7:leave = 1;
			cout << "Thank you";
		}
	} while (leave != 1);
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}


