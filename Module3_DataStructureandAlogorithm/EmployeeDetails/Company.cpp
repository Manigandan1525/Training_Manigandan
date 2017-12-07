#include "Company.h"

#include<iostream>
#include<string>
using namespace std;
int id=100,birth_date,birth_month,birth_year,joining_date,joining_month,joining_year,pay;
string name;
string address;
string dept;
string status;

employee emp;
Company::Company()
{
}


Company::~Company()
{
}
int Company::Search(int id)
{
	//cin >> search;
	int first = 0,middle=0;
	int last = empname.size()-1;
	middle = (first + last) / 2;
	while (first <= last)
	{
		if (empname[middle].getEmp_id() == id)
		{
			return middle;
			break;

		}
		else if (empname[middle].getEmp_id() < id)
		{
			first = middle + 1;
		}
		else
		{
			last = middle - 1;
		}
		middle = (first + last) / 2;
	}
	if (first > last)
	{
		return -1;

	}
}
void Company::createDEtails()
{
	++id;
	emp.setEmp_id(id);
	cout << "Enter name";
	cin >> name;
	emp.setEmp_name(name);
	cout << "Enter Birth date";
	cin >> birth_date;
	emp.setBirth_date(birth_date);
	cout << "Enter birth month";
	cin >> birth_month;
	emp.setBirth_month(birth_month);
	cout << "Enter birth year";
	cin >> birth_year;
	emp.setBirth_year(birth_year);
	cout << "Enter Address";
	cin >> address;
	emp.setAddress(address);
	cout << "Enter DEpartment";
	cin >> dept;
	emp.setDepartment(dept);
	cout << "Enter joining date";
	cin >> joining_date;
	emp.setJoining_date(joining_date);
	cout << "Enter joining month";
	cin >> joining_month;
	emp.setJoining_month(joining_month);
	cout << "Enter joining year";
	cin >> joining_year;
	emp.setJoining_year(joining_year);
	cout << "Enployee Status Project/Bench";
	cin >> status;
	emp.setEmp_status(status);
	cout << "Enter pay";
	cin >> pay;
	emp.setPay(pay);
	empname.push_back(emp);
}
void Company::year()
{
	int get_year = 0;
	cin >> get_year;
	for (int iteration = 0; iteration < empname.size(); iteration++)
	{
		if (get_year == empname[iteration].getJoining_year())
		{
			cout << empname[iteration].getEmp_name()<<endl;
		}
	}

}
void Company::Highest_Pay()
{
	int high=0,value=0;
	string dept;
	cin >> dept;
	for (int iteration = 0; iteration < empname.size(); iteration++)
	{
		if (dept == empname[iteration].getDepartment())
		{
			
			if (high <= empname[iteration].getPay())
			{
				high = empname[iteration].getPay();
				value = iteration;
			}
		}
	}
	
	cout << "The highest pay is: " << empname[value].getPay()<<endl;
display(value);
}
void Company::display(int id)
{
	cout << "Employee ID" << '\t' << empname[id].getEmp_id() << endl;
	cout << "Employee Name" << '\t' << empname[id].getEmp_name() << endl;
	cout << "Employee Birth_date" << '\t' << empname[id].getBirth_date() << endl;
	cout << "Employee Birth month" << '\t' << empname[id].getBirth_month() << endl;
	cout << "Employee Birth year" << '\t' << empname[id].getBirth_year() << endl;
	cout << "Employee Address" << '\t' << empname[id].getBirth_year() << endl;
	cout << "Employee Department" << '\t' << empname[id].getDepartment() << endl;
	cout << "Employee Joining date" << '\t' << empname[id].getJoining_date() << endl;
	cout << "Employee Joining month" << '\t' << empname[id].getJoining_month() << endl;
	cout << "Employee Joining year" << '\t' << empname[id].getJoining_year() << endl;
	cout << "Employee Status" << '\t' << empname[id].getEmp_status() << endl;
	cout << "Pay" << '\t' << empname[id].getPay() << endl;
}
void Company::display()
{
	for (int iteration = 0; iteration < empname.size(); iteration++)
	{
		cout << "Employee ID" << '\t' << empname[iteration].getEmp_id()<<endl;
		cout << "Employee Name" << '\t' << empname[iteration].getEmp_name()<<endl;
		cout << "Employee Birth_date" << '\t' << empname[iteration].getBirth_date() << endl;
		cout << "Employee Birth month" << '\t' << empname[iteration].getBirth_month() << endl;
		cout << "Employee Birth year" << '\t' << empname[iteration].getBirth_year() << endl;
		cout << "Employee Address" << '\t' << empname[iteration].getBirth_year() << endl;
		cout << "Employee Department" << '\t' << empname[iteration].getDepartment() << endl;
		cout << "Employee Joining date" << '\t' << empname[iteration].getJoining_date() << endl;
		cout << "Employee Joining month" << '\t' << empname[iteration].getJoining_month() << endl;
		cout << "Employee Joining year" << '\t' << empname[iteration].getJoining_year() << endl;
		cout << "Employee Status" << '\t' << empname[iteration].getEmp_status() << endl;
		cout << "Pay" << '\t' << empname[iteration].getPay() << endl;

	}

}
string Company::Update_pay()
{
	cin >> id;
	int index = Search(id);
	if (index == -1)
	{
		cout << "Not found! " << id << " is not present in the list.";
	}
	else
	{
		int update = empname[index].getPay();
		update = update + update * 5 / 100;
		empname[index].setPay(update);
		return "updated";
	}
}
string Company::employee_status()
{


}