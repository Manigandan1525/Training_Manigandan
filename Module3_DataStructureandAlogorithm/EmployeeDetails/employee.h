#ifndef employee_HEADER
#define employee_HEADER
#include<iostream>
#include<string>
#include<conio.h>

//#include "employee.cpp"
using namespace std;
class employee
{
private:
	int Emp_id;
	string Emp_name;
	int Birth_date;
	int Birth_month;
	int Birth_year;
	string Address;
	string Department;
	int Joining_date;
	int Joining_month;
	int Joining_year;
	string Emp_status;
	int Pay;


public:
	employee();
	~employee();
	void setEmp_id(int id);
	int getEmp_id();
	void setEmp_name(string name);
	string getEmp_name();
	void setBirth_date(int birth_date);
	int getBirth_date();
	void setBirth_month(int birth_month);
	int getBirth_month();
	void setBirth_year(int birth_year);
	int getBirth_year();
	void setAddress(string address);
	string getAddress();
	void setDepartment(string dept);
	string getDepartment();
	void setJoining_date(int joining_date);
	int getJoining_date();
	void setJoining_month(int joining_month);
	int getJoining_month();
	void setJoining_year(int year);
	int getJoining_year();
	void setEmp_status(string status);
	string getEmp_status();
	void setPay(int pay);
	int getPay();
	

};
#endif
