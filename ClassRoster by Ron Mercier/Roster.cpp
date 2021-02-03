#pragma once
#include <string>
#include <iostream>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"

using namespace std;

Roster::Roster() {
	this->list = -1;
	this->rosterSize = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->list = -1;
	this->classRosterArray = new Student * [rosterSize];
}

void Roster::parseThenAdd(string data) {
	if (list < rosterSize) {
		list++;
	}

	int endOfLine = data.find(",", 0);
	string studentID = data.substr(0, endOfLine);

	int startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	string firstName = data.substr(startOfLine, endOfLine - startOfLine);

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	string lastName = data.substr(startOfLine, endOfLine - startOfLine);

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	string emailAddress = data.substr(startOfLine, endOfLine - startOfLine);

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	string currentAge = data.substr(startOfLine, endOfLine - startOfLine);
	int age = stoi(currentAge);

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	int daysInCourse1 = stoi(data.substr(startOfLine, endOfLine - startOfLine));

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	int daysInCourse2 = stoi(data.substr(startOfLine, endOfLine - startOfLine));

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	int daysInCourse3 = stoi(data.substr(startOfLine, endOfLine - startOfLine));

	startOfLine = endOfLine + 1;
	endOfLine = data.find(",", startOfLine);
	DegreeProgram degreeProgram;
	string degreeProgramStr = data.substr(startOfLine, endOfLine - startOfLine);

	if (degreeProgramStr == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	else if (degreeProgramStr == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeProgramStr == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

bool Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < list; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			cout << "Removed: Student with ID " << studentID << endl;
			classRosterArray[i] = classRosterArray[list];
			list--;
		}
	}
	if (!found) {
		cout << "Student with ID " << studentID << " not found." << endl;
	}
	return found;
}

void Roster::printAll() {
	for (int i = 0; i <= list; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= list; ++i) {
		string tempEmailAddress = classRosterArray[i]->getEmailAddress();
		if (tempEmailAddress.find("@", 0) == string::npos) {
			cout << tempEmailAddress << "\t" << " {missing @ symbol!}" << endl;
		}
		else if (tempEmailAddress.find(".", 0) == string::npos) {
			cout << tempEmailAddress << "\t" << " {Invaild domain!}" << endl;
		}
		else if (tempEmailAddress.find(" ", 0) != string::npos) {
			cout << tempEmailAddress << "\t" << " {no spaces!}" << endl;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int average = 0;
	for (int i = 0; i <= list; ++i) {
		string tempID = classRosterArray[i]->getStudentID();
		if (tempID == studentID) {
			average = ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3);
			cout << "Student ID " << studentID << " average is: " << average << endl;
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[Student::daysArray];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	classRosterArray[list] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}


void Roster::printDegreeProgramType(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; ++i) {
		DegreeProgram tempDegree = classRosterArray[i]->getDegreeProgram();
		if (tempDegree == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Student* Roster::getStudent(int list) {
	return classRosterArray[list];
}

Roster::~Roster() {
	for (int i = 0; i < list; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}
