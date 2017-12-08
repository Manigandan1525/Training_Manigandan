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
	int Age;
	string Gender;
	int Mobile_Number;
	string Address;
	string Department;
	int Joining_year;
	string Edu_Qualification;
	string Emp_status;
	string Project_name;
	int Pay;


public:
	employee();
	~employee();
	void setEmp_id(int id);
	int getEmp_id();
	void setEmp_name(string name);
	string getEmp_name();
	void setAge(int age);
	int getAge();
	void setGender(string gender);
	string getGender();
	void setMobile_Number(int number);
	int getMobile_Number();
	void setAddress(string address);
	string getAddress();
	void setDepartment(string dept);
	string getDepartment();
	void setJoining_year(int year);
	int getJoining_year();
	void setEdu_Qualification(string qualification);
	string getEdu_Qualification();
	void setEmp_status(string status);
	string getEmp_status();
	void setProject_name(string project_name);
	string getProject_name();
	void setPay(int pay);
	int getPay();
	

};
#endif
