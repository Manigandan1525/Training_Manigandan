#ifndef employee_HEADER
#define employee_HEADER
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;
class employee
{
private:
	string Emp_id;
	string Emp_name;
	int Year;
	int Month;
	int Date;
	string Gender;
	int Mobile_Number;
	string Address;
	string Department;
	int Joining_year;
	string Edu_Qualification;
	string Emp_status;
	string Project_name;
	double Pay;


public:
	employee();
	~employee();
	void setEmp_id(string id);
	string getEmp_id();
	void setEmp_name(string name);
	string getEmp_name();
	void set_year(int year);
	int get_year();
	void set_month(int month);
	int get_month();
	void set_date(int date);
	int get_date();
	void setGender(string gender);
	string getGender();
	void setMobile_Number(long long number);
	long long getMobile_Number();
	void setAddress(string address);
	string getAddress();
	void setDepartment(string dept);
	string getDepartment();
	void setJoining_year(int joining_year);
	int getJoining_year();
	void setEdu_Qualification(string qualification);
	string getEdu_Qualification();
	void setEmp_status(string);
	string getEmp_status();
	void setProject_name(string project_name);
	string getProject_name();
	void setPay(double pay);
	double getPay();
	

};
#endif
