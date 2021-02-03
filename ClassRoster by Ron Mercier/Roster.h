#pragma once
#include <string>
#include "Degree.h"
#include "Student.h"

using namespace std;

class Roster {
private:
	int list;
	int rosterSize;
	Student** classRosterArray;

public:
	Roster();
	Roster(int rosterSize);
	void parseThenAdd(string data);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	bool remove(string StudentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printDegreeProgramType(DegreeProgram degreeProgram);
	Student* getStudent(int list);
	~Roster();
};