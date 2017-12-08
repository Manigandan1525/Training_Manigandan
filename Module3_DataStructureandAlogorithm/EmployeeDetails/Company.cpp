#include "Company.h"

#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int id=100,age,number,joining_year,pay,count,size;
int front = -1, rear = -1;

string name,gender,qualification;
string address;
string dept;
string status,project_name;

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
void Company::createDetails()
{
	++id;
	emp.setEmp_id(id);
	cout << "Employee name:  ";
	name:
	cin >> name;
	bool valid_name=name_validation(name);
	if (valid_name == 0)
	{
		cout << "Enter valid name";
		goto name;
	}
	emp.setEmp_name(name);
	cout << "Gender:  ";
	gender:
	cin >> gender;
	bool valid_gender = gender_validation(gender);
	if (valid_gender == 0)
	{
		cout << "Enter valid gender";
		goto gender;
	}
	emp.setGender(gender); 
	cout << "Age:  ";
	age:
	cin >> age;
	bool valid_age = age_validation(age);
	if (valid_age == 0)
	{
		cout << "Enter valid age";
		goto age;
	}
	emp.setAge(age);
	cout << "Mobile_Number:  ";
	cin >> number;
	emp.setMobile_Number(number);
	cout << "Address:  ";
	cin >> address;
	emp.setAddress(address);
	cout << "Department:  ";
	cin >> dept;
	emp.setDepartment(dept);
	cout << "Employee joining year:  ";
	year:
	cin >> joining_year;
	bool valid_year = year_validation(joining_year);
	if (valid_year == 0)
	{
		cout << "Enter valid age";
		goto year;
	}
	emp.setJoining_year(joining_year);
	cout << "Education Qualification:  ";
	cin >> qualification;
	emp.setEdu_Qualification(qualification);
	cout << "Enployee Status Project/Bench:  ";
	status:
	cin >> status;
	bool valid_status = status_validation(status);
	if (valid_status == 0)
	{
		cout << "Enter valid age";
		goto status;
	}
	emp.setEmp_status(status);
	if (status == "Bench" || status == "bench" || status == "BENCH")
	{
		project_name = "NULL";
	}
	else
	{
		cout << "Enter project name";
		cin >> project_name;
	}
	emp.setProject_name(project_name);
	cout << "Employee Pay:  ";
	cin >> pay;
	emp.setPay(pay);
	empname.push_back(emp);
}
void Company::year()
{
	int get_year = 0;
	cin >> get_year;
	cout << "Employee Names: " << endl;
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
	cout << '\n' << "Employee DEtail" << endl;
display(value);
}
void Company::display(int id)
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << "Employee ID:" << '\t' << empname[id].getEmp_id() << endl;
	cout << "Employee Name:" << '\t' <<'\t'<< empname[id].getEmp_name() << endl;
	cout << "Employee Age:" << '\t' <<'\t'<< empname[id].getAge() << endl;
	cout << "Employee Gender:" << '\t' << empname[id].getGender() << endl;
	cout << "Employee Mobile_Number:" << '\t' << empname[id].getMobile_Number() << endl;
	cout << "Employee Address:" << '\t' << empname[id].getAddress() << endl;
	cout << "Employee Department:" << '\t' << empname[id].getDepartment() << endl;
	cout << "Employee Joining year:" << '\t' << empname[id].getJoining_year() << endl;
	cout << "Employee Qualification:" << '\t' << empname[id].getEdu_Qualification() << endl;
	cout << "Employee Status:" << '\t' << empname[id].getEmp_status() << endl;
	cout << "Project Name:" << '\t' << '\t'<<empname[id].getProject_name() << endl;
	cout << "Employee Pay:" << '\t' << '\t'<<empname[id].getPay() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void Company::display()
{
	for (int iteration = 0; iteration < empname.size(); iteration++)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Employee ID:" << '\t' << empname[iteration].getEmp_id() << endl;
		cout << "Employee Name:" << '\t' <<'\t'<< empname[iteration].getEmp_name() << endl;
		cout << "Employee Age:" << '\t' << '\t'<<empname[iteration].getAge() << endl;
		cout << "Employee Gender:" << '\t' << empname[iteration].getGender() << endl;
		cout << "Employee Mobile_Number:" << '\t' << empname[iteration].getMobile_Number() << endl;
		cout << "Employee Address:" << '\t' << empname[iteration].getAddress() << endl;
		cout << "Employee Department:" << '\t' << empname[iteration].getDepartment() << endl;
		cout << "Employee Joining year:" << '\t' << empname[iteration].getJoining_year() << endl;
		cout << "Employee Qualification:" << '\t' << empname[iteration].getEdu_Qualification() << endl;
		cout << "Employee Status:" << '\t' << empname[iteration].getEmp_status() << endl;
		cout << "Project Name:" << '\t' << '\t' << empname[iteration].getProject_name() << endl;
		cout << "Employee Pay:" << '\t' << '\t'<<empname[iteration].getPay() << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

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
		return " pay updated";

	}
	cout << "updated pay value is:" << empname[index].getPay() << endl;
}
string Company::employee_status()
{
	cin >> id;
	int id1 = Search(id);
	empname[id1].setEmp_status("Bench");
	empname[id1].setProject_name("NULL");
	if (isFull())
	{
		printf("queue is full\n");
	}
	if (isEmpty())
		front = rear = 0;
	else
		rear = (rear + 1) % empname.size();

	emp_status.push_back(empname[id1]);

	return "Employee removed from project";
}
string Company::pop()
{
	cin >> id;
	int id1 = Search(id);
	empname[id1].setEmp_status("Project");
	cout << "Enter project name";
	cin >> project_name;
	empname[id1].setProject_name(project_name);
	if (isEmpty())
	{
		printf("queue is empty\n");
		
	}
	else if (front == rear)
		front = rear = -1;
	else
	{
		front = (front + 1) % empname.size();
	}
	return "Employee to be allocated in project";
}

bool Company::isEmpty(){
	return (front == -1 && rear == -1) ? true : false;
}

bool Company::isFull(){
	
	return (rear + 1) % (empname.size()) == front ? true : false;
}


string Company::print()
{
	if (!isEmpty())
	{
		for (int iteration = 0; iteration < empname.size(); iteration++)
		{
			if (empname[iteration].getEmp_status() == "Bench" || empname[iteration].getEmp_status() == "bench" || empname[iteration].getEmp_status() == "BENCH")
			{
				cout << "Employee ID" << '\t' << '\t' << empname[iteration].getEmp_id() << endl;
				cout << "Employee Status:" << '\t' << empname[iteration].getEmp_status() << endl;
				cout << "Project Name:" << '\t' << '\t' << empname[iteration].getProject_name() << endl;
			}
		}
	}
	else
	{
		return "Bench is Empty";
	}
}



/*
string Company::push()
{
	cin >> id;
	int id1 = Search(id);
	empname[id1].setEmp_status("Bench");
	emp_status.push(empname[id1]);
	return "Employee in bench";
}
string Company::pop()
{
	if (emp_status.empty())
	{
		return "bench is free";
	}
	else
	{
		int id = emp_status.front().getEmp_id();
		int id1 = Search(id);
		empname[id1].setEmp_status("Project");
		emp_status.pop();
		return "employee moved in project";
	}
}*/
bool Company::name_validation(string name)
{
	int iteration = 0, count = 0;
	for (iteration = 0; name[iteration] != '\0'; iteration++)
	{
		if (isalpha(name[size]))
		{
			count++;
		}
	}
	if (count == iteration)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool Company::gender_validation(string gender)
{
	if (gender == "male" || gender == "MALE" || gender == "female" || gender == "FEMALE" || gender == "transgender" || gender == "TRANSGENDER")
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Company::age_validation(int age)
{
	if (age >= 20 && age <= 55)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Company::year_validation(int year)
{
	if (year >=1965  && year <= 2017)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Company::status_validation(string status)
{
	if (status == "project" || status == "PROJECT" || status == "bench" || status == "BENCH")
	{
		return true;
	}
	else
	{
		return false;
	}
}
//string Company::push()
//{

//}
//string Company::pop()
//{
