#include"employee.h"

employee::employee()
{

}
employee::~employee()
{

}
void employee::setEmp_id(string id)
{
	this->Emp_id = id;
}

string employee::getEmp_id()
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

void employee::set_year(int year)
{
	this->Year = year;
}

int employee::get_year()
{
	return this->Year;
}


void employee::set_month(int month)
{
	this->Month = month;
}

int employee::get_month()
{
	return this->Month;
}

void employee::set_date(int date)
{
	this->Date = date;
}

int employee::get_date()
{
	return this->Date;
}
void employee::setGender(string gender)
{
	this->Gender = gender;
}

string employee::getGender()
{
	return this->Gender;
}

void employee::setMobile_Number(long long number)
{
	this->Mobile_Number = number;
}

long long employee::getMobile_Number()
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

void employee::setPay(double pay)
{
	this->Pay = pay;
}

double employee::getPay()
{
	return this->Pay;
}