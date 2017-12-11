#include "employee.h"
#include "Company.h"
#include<iostream>
using namespace std;
int main()
{
	Company cmp;
	int option, no_of_employee, leave = 0;
	string result;
	//cmp.createDEtails();
	//cmp.display();
	cout << "Enter number of employees:"<<endl;
	cin >> no_of_employee;
	for (int iteration = 0; iteration < no_of_employee; iteration++)
	{
		cmp.createDetails();
	}
	
	do
	{
		result = "null";
		cout <<'\n'<< "1. Add New Employee\n2. Display names of employee from a particular year of joining" << '\n'
			<< "3. Display all details of employee having highest pay\n4. Display all details of all employees in ascending order"
			<< '\n' <<"5. Update pay of a particular employee(Update pay by 5%)\n6. Enployee removed from project\n7. Allocate project\n8.Display bench employee\n9. Exit" << endl;
		cout << "\n" << "Enter your option" << endl;
		cin >> option;
		switch (option)
		{
		case 1:cmp.createDetails();
			   break;
		case 2:cout << "Enter a particular year: "<<endl;
			   cmp.year();
			   break;
		case 3:cout << "Enter particular Department: "<<endl;
			   cmp.Highest_Pay();
			   break;
		case 4:cout << "Employee Details"<<endl;
			   cmp.display();
			   break;
		case 5:cout << "Enter employee ID:"<<endl;
			  result= cmp.Update_pay();
			  cout << result;
			   break;
		case 6:cout << "Enter employee ID:"<<endl;
			cmp.employee_status();
			break;
		case 7:cmp.pop_new();
			break;
		case 8:cmp.print();
			break;
		case 9:leave = 1;
			cout << "Thank you";
			break;
	
		}
	} while (leave != 1);
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}


