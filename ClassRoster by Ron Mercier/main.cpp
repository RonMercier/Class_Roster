#include <iostream>
#include <string>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"

using namespace std;

int main() {
	int numStudents = 5;
	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ron,Mercier,rmerci3@student.wgu.edu,34,25,35,30,SOFTWARE",
	};
	Roster* classRoster = new Roster(numStudents);

	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Student ID: #001406973" << endl;
	cout << "Programming language: C++" << endl;
	cout << "JYM1 Task 1: Class Roster by Ron Mercier" << endl << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]);
	}
	

	cout << "Student Roster:" << endl;
	classRoster->printAll();

	cout << endl;

	cout << "Invalid Emails:" << endl;
	classRoster->printInvalidEmails();

	cout << endl;

	cout << "Average days in course:" << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
	}
	
	cout << endl;

	cout << "Students currently enrolled in the Software Degree Program: " << endl;
	classRoster->printDegreeProgramType(DegreeProgram::SOFTWARE);
	cout << "Complete." << endl << endl;

	cout << "Removing student from roster...." << endl;
	classRoster->remove("A3");
	cout << "Complete." << endl << endl;

	cout << "Updated student roster:" << endl;
	classRoster->printAll();
	
	cout << endl;

	classRoster->remove("A3");
	
	cout << endl;

	system("pause");
	return 0;
}