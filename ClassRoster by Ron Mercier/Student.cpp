#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include "Degree.h"
#include "Student.h"

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArray; ++i) {
		this->daysInCourse[i] = 0;
	}
	//this->degreeProgram = degreeProgram;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArray; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

//Getters and Setters
string Student::getStudentID() {
	return this->studentID;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Student::getLastName() {
	return this->lastName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

void Student::setEmailAddress(string EmailAddress) {
	this->emailAddress = emailAddress;
}

int Student::getAge() {
	return this->age;
}

void Student::setAge(int age) {
	this->age = age;
}

int *Student::getDaysInCourse() {
	return this->daysInCourse;
}

void *Student::setDaysInCourse(int daysInCourse[], int daysArray) {
	for (int i = 0; i < daysArray; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << left << "ID: " << setw(5) << studentID;
	cout << left << "First: " << setw(8) << firstName;
	cout << left << "Last: " << setw(10) << lastName;
	cout << left << "Email: " << setw(25) << emailAddress;
	cout << left << "Age: " << setw(4) << age;
	int* day = getDaysInCourse();
	cout << left << "Days in course: ";
	cout << left << day[0] << "," << day[1] << "," << setw(5) << day[2] << setw(10);
	cout << left << setw(10) << degreeProgramStr[(int)getDegreeProgram()] << endl;
}

Student::~Student() {

}