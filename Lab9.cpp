/*****************************************************************************************
Project Name: Lab 9
Name: Kristopher Lowell
Date Completed: 8/9/2018
Purpose: Read from a file, alter one word, and write altered data into another file.
Also, read from a file of employee records, then find a record by one of the data points.
*****************************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file1;
	ofstream file2;

	file1.open("test1.txt");
	file2.open("test2.txt");

	string word;
	vector <string> line;

	if (file1.is_open() && file2.is_open())
	{
		while (!file1.eof())
		{
			while (file1.peek() != '\n' && !file1.eof())
			{
				file1 >> word;
				line.push_back(word);
			}

			if (!file1.eof())
				file1.ignore(INT_MAX, '\n');

			for (unsigned i = 0; i < line.size(); i++)
			{
				if (!line[i].compare("John"))
					line[i] = "Smith";

				file2 << line[i] << " ";
			}

			if (!file1.eof())
				file2 << endl;

			line.clear();
		}

		file1.close();
		file2.close();
	}

	ifstream file3;
	file3.open("test3.txt");

	Employee currentEmp;
	vector <Employee> faculty;

	string empLine;
	unsigned long number;

	bool found = false;

	if (file3.is_open())
	{
		while (!file3.eof())
		{
			getline(file3, empLine);
			stringstream ss(empLine);

			getline(ss, word, ',');
			number = stoul(word);
			currentEmp.setNumber(number);
			
			getline(ss, word, ',');
			currentEmp.setfirstName(word);

			getline(ss, word, ',');
			currentEmp.setLastName(word);

			getline(ss, word, ',');
			currentEmp.setDepartment(word);

			getline(ss, word, '\n');
			number = stoul(word);
			currentEmp.setSalary(number);

			faculty.push_back(currentEmp);
		}

		cout << "Enter the employee number: ";
		cin >> number;

		for (unsigned i = 0; i < faculty.size(); i++)
		{
			if (faculty[i].getNumber() == number)
			{
				found = true;
				cout << "Employee's first name: " << faculty[i].getFirstName() << endl;
				cout << "Employee's salary: " << faculty[i].getSalary() << endl;
			}
		}
		
		if (!found)
			cout << "Sorry, no employee with that number was found." << endl;

		faculty.clear();
		file3.close();
	}
	
	return 0;
}