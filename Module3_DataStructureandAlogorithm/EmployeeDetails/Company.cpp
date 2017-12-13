#include "Company.h"
#include "queue_concept.h"
#include <limits>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int id=100,year,month,date,joining_year,count;
float new_age,new_year;
long long number;
string emp_id="EMP";
double pay;

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
int Company::Search(string emp_id)
{

	int first = 0,middle = 0;
	int last = empname.size()-1;
	middle = (first + last) / 2;
	while (first <= last)
	{
		if (empname[middle].getEmp_id() == emp_id)
		{
			return middle;
			break;

		}
		else if (empname[middle].getEmp_id() < emp_id)
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
	emp_id = "EMP";
	string sample= to_string(id);
	emp_id = emp_id + sample;
	
	cout << '\n' << "Employee ID:" << "\t\t";
	cout << emp_id << endl;
	emp.setEmp_id(emp_id);
	cout << "Employee name:"<<"\t\t";
	getline(cin>>ws , name);
	while (1)
	{
		if (!name_validation(name))
		{
			cout << "Enter valid name:" << "\t";
			cin >> name;
		}
		else
		{
			break;
		}
	}
	emp.setEmp_name(name);
	cout << "Gender:  "<<"\t\t";
	getline(cin>>ws,gender);
	while (1)
	{
		if (!gender_validation(gender))
		{
			cout  <<"Enter valid gender:" << "\t";
			cin >> gender;
		}
		else
		{
			break;
		}
	}
	emp.setGender(gender); 
	cout << "Mobile_Number:" << "\t\t";
	cin >> number;
	//number=numberValidation(number);
	emp.setMobile_Number(number);
	cout << "Address:" << "\t\t";
	cin >> address;
	emp.setAddress(address);
	cout << "Department:" << "\t\t";
	cin >> dept;
	emp.setDepartment(dept);
	cout << "Edu Qualification:" << "\t";
	cin >> qualification;
	emp.setEdu_Qualification(qualification);
	emp.setEmp_status(status);
    cout << "Enter project name:"<<"\t";
	getline(cin>>ws, project_name);
	emp.setProject_name(project_name);
	cout << "Enter birth year";
	cin >> year;
	emp.set_year(year);
	cout << "Enter birth month";
	while (1)
	{
		cin >> month;
		if (1 <= month && month <= 12)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	emp.set_month(month);
	cout << "Enter birth name";
	cin >> date;
	while (1)
	{
		cin >> date;
		if (1 <= date&&date <= 31)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	emp.set_date(date);
	/*cout << "Age:  " << "\t\t\t";
	cin >> new_age;
	int check_age = int(new_age);
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid Age: " << '\t';
			cin >> new_age;
			check_age = int(new_age);
			continue;
		}
		else if (check_age != new_age)
		{
			cout << "Enter valid Age: " << '\t';
			cin >> new_age;
			check_age = int(new_age);
			continue;
		}

		else if (!age_validation(new_age))
		{
			cout << "Enter valid Age:" << '\t';
			cin >> new_age;
			check_age = int(new_age);
			continue;
		}
		else
		{
			age = new_age;
			break;
		}

	}
	emp.setAge(age);*/
	cout << "Employee joining year:" << "\t";
	cin >> new_year;
	int check_year = int(new_year);
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid year: " << '\t';
			cin >> new_year;
			check_year = int(new_year);
			continue;
		}
		else if (check_year != new_year)
		{
			cout << "Enter valid year: " << '\t';
			cin >> new_year;
			check_year = int(new_year);
			continue;
		}

		else if (!year_validation(new_year))
		{
			cout << "Enter valid year:" << '\t';
			cin >> new_year;
			check_year = int(new_year);
			continue;
		}
		else
		{
			joining_year = new_year;
			break;
		}

	}
	emp.setJoining_year(joining_year);
	cout << "Employee Pay:" << "\t\t";
	cin >> pay;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid pay: " << '\t';
			cin >> pay;
			continue;
		}
		else
		{
			break;
		}
	}
	emp.setPay(pay);
	empname.push_back(emp);
}
void Company::emp_year()
{
	int get_year,year_valid=0;
	cin >> get_year;
	
	for (int iteration = 0; iteration < empname.size(); iteration++)
	{
		if (get_year == empname[iteration].getJoining_year())
		{
			cout << "Employee Name:  "<<'\t';
			cout << empname[iteration].getEmp_name()<<endl;
			year_valid++;

		}
	}
	if (year_valid == 0)
	{
		cout << "None of the Employee joining in this year" << endl;
	}

}
void Company::Highest_Pay()
{
	int high = 0, value = 0, valid_dept = 0;
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
				valid_dept++;
			}
		}
	}
	if (valid_dept == 0)
	{
		cout << "You entered unknown Department";
	}
	else
	{
		cout << "The highest pay is: " << empname[value].getPay() << endl;
		cout << '\n' << "Employee DEtail" << endl;
		display(value);
	}
}
void Company::display(int id) //Index 
{
	cout <<'\n'<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << "Employee ID:" << '\t' <<'\t'<<empname[id].getEmp_id() << endl;
	cout << "Employee Name:" << '\t' <<'\t'<< empname[id].getEmp_name() << endl;
	cout << "Employee Year:" << '\t' <<'\t'<< empname[id].get_year() << endl;
	cout << "Employee Month:" << '\t' << '\t' << empname[id].get_month() << endl;
	cout << "Employee Date:" << '\t' << '\t' << empname[id].get_date() << endl;
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
		display(iteration);
	}

}
void Company::Update_pay()
{
	cin >> emp_id;
	int index = Search(emp_id);
	if (index == -1)
	{
		cout << "Not found! " << '\n'<< "You entered wrong employee ID";
	}
	else
	{
		double update = empname[index].getPay();
		update = update + (update) * (0.05);
		empname[index].setPay(update);
		cout << "updated pay value is:" << empname[index].getPay() << endl;

	}
	
}
int Company::employee_status()
{
	cin >> emp_id;
	int index = Search(emp_id);
	if (index == -1)
	{
		cout << "Enter wrong employee ID";
		return 0;
	}
		if (empname[index].getEmp_status() == "BENCH")
	{
		cout << "This employee already in bench" << endl;
	}
	
	else
	{
		empname[index].setEmp_status("BENCH");
		empname[index].setProject_name("NONE");
		empname[index].setDepartment("NONE");
		queue.push(empname[index]);
		cout << "Employee moved to Bench" << endl;
	}
}
void Company::new_status()
{
	string emp_id1=queue.pop();
	if (emp_id1 != "Empty")
	{
		int index = Search(emp_id1);
		empname[index].setEmp_status("project");
		string dept;
		cout << "Enter Department";
		getline(cin >>ws, dept);
		empname[index].setProject_name(dept);
		string project_name;
		cout << "Enter Project_name";
		getline(cin>>ws,project_name);
		empname[index].setDepartment(project_name);
		cout << "Allocated project to empoyee" << endl;
	}

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
				cout << "tEmployee ID" << '\t' << '\t' << empname[iteration].getEmp_id() << endl;
				cout << "Employee Status:" << '\t' << empname[iteration].getEmp_status() << endl;
				cout << "Project Name:" << '\t' << '\t' << empname[iteration].getProject_name() << endl;
			}
		}
	}
}

bool Company::name_validation(string name)
{
	int iteration = 0, count = 0;
	for (iteration = 0; name[iteration] != '\0'; iteration++)
	{
		if (isalpha(name[iteration]) || isspace(name[iteration]))
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
	if (gender == "male" || gender == "MALE" ||gender == "female" || 
 gender == "FEMALE" || gender == "transgender"  || gender == "TRANSGENDER")
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Company:: numberValidation(int number)
{
	while (1);
}
bool Company::age_validation(int age)
{
	if (age >= 22 && age <= 55)
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
	if (year >=1990 )
	{
		return true;
	}
	else
	{
		return false;
	}
}
