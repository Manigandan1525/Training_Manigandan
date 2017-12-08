#include"employee.h"

employee::employee()
{

}
employee::~employee()
{

}
void employee::setEmp_id(int id)
{
	this->Emp_id = id;
}

int employee::getEmp_id()
{
	return this->Emp_id;
}

void employee::setEmp_name(string name)
{
	this->Emp_name = name;
}

string employee::getEmp_name()
{
	return this->Emp_name;
}

void employee::setAge(int age)
{
	this->Age = age;
}

int employee::getAge()
{
	return this->Age;
}

void employee::setGender(string gender)
{
	this->Gender = gender;
}

string employee::getGender()
{
	return this->Gender;
}

void employee::setMobile_Number(int number)
{
	this->Mobile_Number = number;
}

int employee::getMobile_Number()
{
	return this->Mobile_Number;
}

void employee::setAddress(string address)
{
	this->Address = address;
}

string employee::getAddress()
{
	return this->Address;
}

void employee::setDepartment(string dept)
{
	this->Department = dept;
}

string employee::getDepartment()
{
	return this->Department;
}

void employee::setJoining_year(int joining_year)
{
	this->Joining_year = joining_year;
}

int employee::getJoining_year()
{
	return this->Joining_year;
}

void employee::setEdu_Qualification(string qualification)
{
	this->Edu_Qualification = qualification;
}

string employee::getEdu_Qualification()
{
	return this->Edu_Qualification;
}

void employee::setEmp_status(string status)
{
	this->Emp_status = status;
}

string employee::getEmp_status()
{
	return this->Emp_status;
}

void employee::setProject_name(string project_name)
{
	this->Project_name = project_name;
}

string employee::getProject_name()
{
	return this->Project_name;
}

void employee::setPay(int pay)
{
	this->Pay = pay;
}

int employee::getPay()
{
	return this->Pay;
}