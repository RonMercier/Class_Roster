#pragma once
#include <iomanip>
#include <string>
#include "Degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	const static int daysArray = 3;

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	void print();

	/*accessors*/
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	void* setDaysInCourse(int daysInCourse[], int daysArray);
	DegreeProgram getDegreeProgram();

	/*mutators*/
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void* setDaysInCourse(int *daysInCourse[daysArray]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	

	~Student();  
};