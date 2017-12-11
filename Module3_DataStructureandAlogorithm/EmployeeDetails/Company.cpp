#include "Company.h"
#include "queue_concept.h"
#include <limits>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int id=100,age,number,joining_year,pay,count,size;
int bench_count = 0,current_employee=0;
int front = -1, rear = -1;

string name,gender,qualification;
string address;
string dept;
string status="project",project_name;
queue_concept queue;
employee emp;
Company::Company()
{
}


Company::~Company()
{
}
int Company::Search(int id)
{

	int first = 0,middle = 0;
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
	cout <<'\n'<< "Employee name:"<<"\t\t";
	NAME:
	cin >> name;
	
	if (!name_validation(name))
	{
		cout << "Enter valid name" << "\t\t";
		goto NAME;
	}
	emp.setEmp_name(name);
	cout << "Gender:  "<<"\t\t";
	GENDER:
	cin >> gender;

	if (!gender_validation(gender))
	{
		cout << "Enter valid gender" << "\t\t";
		goto GENDER;
	}
	emp.setGender(gender); 
	cout << "Age:  " << "\t\t\t";
AGE:
	cin >> age;
	 if (cin.fail())
	{
		age = CheckInput();
		
	}
	 if (age_validation(age))
		 {
			 emp.setAge(age);

		 }
	 else
	 {
		 cout << "Enter valid age" << "\t\t";
		 goto AGE;
	 }
	 cout << "Mobile_Number:" << "\t\t";
	cin >> number;
	emp.setMobile_Number(number);
	cout << "Address:" << "\t\t";
	cin >> address;
	emp.setAddress(address);
	cout << "Department:" << "\t";
	cin >> dept;
	emp.setDepartment(dept);
	cout << "Employee joining year:" << "\t\t";
YEAR:
	cin >> joining_year;
	if (!year_validation(joining_year))
	{
		cout << "Enter valid year";
		goto YEAR;
	}
	else
	{
	emp.setJoining_year(joining_year);
	}
	cout << "Education Qualification:" << "\t\t";
	cin >> qualification;
	emp.setEdu_Qualification(qualification);
	cout << "Employee Status" << "\n";
	emp.setEmp_status(status);
	
	//bool valid_status = status_validation(status);
    cout << "Enter project name:"<<"\t\t";
	cin >> project_name;
	emp.setProject_name(project_name);
	cout << "Employee Pay:" << "\t\t";
	cin >> pay;
	emp.setPay(pay);
	empname.push_back(emp);
}
void Company::year()
{
	int get_year = 0;
	cin >> get_year;
	cout << "Employee Names:  " ;
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
	cout <<'\n'<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << "Employee ID:" << '\t' << '\t'<<empname[id].getEmp_id() << endl;
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
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void Company::display()
{
	for (int iteration = 0; iteration < empname.size(); iteration++)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

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
	current_employee = Search(id);
	int first = current_employee;
	empname[current_employee].setEmp_status("BENCH");
	empname[current_employee].setProject_name("NONE");
	empname[current_employee].setDepartment("NONE");
	queue.push(empname[current_employee]);
	return "Employee removed from project";
}
string Company::pop_new()
{
	int id=queue.pop();
	if (id == 0)
	{
		cout << "Bench is empty";
	}
	else
	{
		empname[id].setEmp_status("project");
		string dept;
		cout << "Enter Department";
		cin >> dept;
		empname[id].setProject_name(dept);
		string project_name;
		cout << "Enter Project_name";
		cin >> project_name;
		empname[id].setDepartment(project_name);
	}
	return "Employee to be allocated in project";
}

void Company::print()
{
	if (queue.print())
	{
		cout<<"Bench is empty";
	}
	else
	{
		for (int iteration = 0; iteration < empname.size(); iteration++)
		{
			if (empname[iteration].getEmp_status() == "BENCH")
			{
				cout << "Employee ID" << '\t' << '\t' << empname[iteration].getEmp_id() << endl;
				cout << "Employee Status:" << '\t' << empname[iteration].getEmp_status() << endl;
				cout << "Project Name:" << '\t' << '\t' << empname[iteration].getProject_name() << endl;
			}
		}
	}
}


int Company::CheckInput( )
{
	int data;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter correct input"<<endl;
			cin >> data;
		}
		else if (!cin.fail())
		{
			return data;
			break;
		}
	}
	
}
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
