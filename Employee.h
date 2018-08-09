/*****************************************************************************************
Project Name: Lab 9
Name: Kristopher Lowell
Date Completed: 8/9/2018
Purpose: Read from a file, alter one word, and write altered data into another file.
Also, read from a file of employee records, then find a record by one of the data points.
*****************************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
public:
	Employee() {};

	unsigned getNumber() { return number; };
	string getFirstName() { return firstName; };
	string getLastName() { return lastName; };
	string getDepartment() { return department; };
	unsigned getSalary() { return salary; };

	void setNumber(unsigned numberVal) { number = numberVal; };
	void setfirstName(string firstNameVal) { firstName = firstNameVal; };
	void setLastName(string lastNameVal) { lastName = lastNameVal; };
	void setDepartment(string departmentVal) { department = departmentVal; };
	void setSalary(unsigned salaryVal) { salary = salaryVal; };

private:
	unsigned long number;
	string firstName;
	string lastName;
	string department;
	unsigned long salary;
};

#endif