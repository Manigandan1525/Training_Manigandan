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

void employee::setBirth_date(int birth_date)
{
	this->Birth_date = birth_date;
}

int employee::getBirth_date()
{
	return this->Birth_date;
}

void employee::setBirth_month(int birth_month)
{
	this->Birth_month = birth_month;
}

int employee::getBirth_month()
{
	return this->Birth_month;
}

void employee::setBirth_year(int birth_year)
{
	this->Birth_date = birth_year;
}

int employee::getBirth_year()
{
	return this->Birth_year;
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

void employee::setJoining_date(int joining_date)
{
	this->Joining_date = joining_date;
}

int employee::getJoining_date()
{
	return this->Joining_date;
}

void employee::setJoining_month(int joining_month)
{
	this->Joining_month = joining_month;
}

int employee::getJoining_month()
{
	return this->Joining_month;
}

void employee::setJoining_year(int joining_year)
{
	this->Joining_year = joining_year;
}

int employee::getJoining_year()
{
	return this->Joining_year;
}

void employee::setEmp_status(string status)
{
	this->Emp_status = status;
}

string employee::getEmp_status()
{
	return this->Emp_status;
}

void employee::setPay(int pay)
{
	this->Pay = pay;
}

int employee::getPay()
{
	return this->Pay;
}