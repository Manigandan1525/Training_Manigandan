//
#include "employee.h"
#include "Company.h"
#include<iostream>
using namespace std;

int main()
{
	Company cmp;
	char new_emp;

	int option, no_of_employee, leave = 0;
	float new_option;

	cout << "Add New employees(y/n):";

	/*cin >> new_emp;
	int check_emp = new_emp;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid number: " << '\t';
			cin >> new_emp;
			check_emp = int(new_emp);
			continue;
		}
		else if (check_emp != new_emp)
		{
			cout << "Enter correct option: " << '\t';
			cin >> new_emp;
			check_emp = int(new_emp);
			continue;
		}
		else if (new_emp <=0)
		{
			cout << "Enter valid option:" << '\t';
			cin >> new_option;
			check_emp = int(new_emp);
			continue;
		}
		else
		{
			no_of_employee = new_emp;
			break;
		}
	}
	for (int iteration = 0; iteration < no_of_employee; iteration++)
	{
		cmp.createDetails();
	}*/
	while (1)
	{
		cin >> new_emp;
		if (new_emp == 'y')
		{
			cmp.createDetails();
			break;
		}
		else if (new_emp == 'n')
		{
			break;
		}
		else
		{
			cout << "Enter correct option ";
		}
	}
	do
	{
		cout <<'\n'<< "1. Add New Employee\n2. Display names of employee from a particular year of joining" << '\n'
			<< "3. Display all details of employee having highest pay\n4. Display all details of all employees in ascending order"
			<< '\n' <<"5. Update pay of a particular employee(Update pay by 5%)\n6. Enployee removed from project\n7. Allocate project\n8. Display bench employee\n9. Exit" << endl;

		cout << "\n" << "Enter your option" << endl;
		cin >> new_option;
		int check_option = int(new_option);
		while (1)
		{
			
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter correct option: " << '\t';
				cin >> new_option;
				check_option = int(new_option);
				continue;
			}
			else if (check_option != new_option)
			{
				cout << "Enter correct option: " << '\t';
				cin >> new_option;
				check_option = int(new_option);
				continue;
			}
			else if (new_option<1 || new_option>9)
			{
				cout << "Enter valid option:" << '\t';
				cin >> new_option;
				check_option = int(new_option);
				continue;
			}
			else
			{
				option = new_option;
				break;
			}

		}
		switch (option)
		{
		case 1:cmp.createDetails();
			   break;
		case 2:cout << "Enter a particular year: "<<endl;
			   cmp.emp_year();
			   break;
		case 3:cout << "Enter particular Department: "<<endl;
			   cmp.Highest_Pay();
			   break;
		case 4:cout << "Employee Details"<<endl;
			   cmp.display();
			   break;
		case 5:cout << "Enter employee ID:"<<endl;
			   cmp.Update_pay();
			   break;
		case 6:cout << "Enter employee ID:"<<endl;
			   cmp.employee_status();
			   break;
		case 7:cmp.new_status();
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


