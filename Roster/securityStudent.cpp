#include <iostream>
#include <iomanip>
#include "SecurityStudent.h"

using namespace std;

//constructors
SecurityStudent::SecurityStudent() {
	setDegreeProgram(DEGREE_TYPE);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
: Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram) {
	setDegreeProgram(DEGREE_TYPE);
}

// overridden methods
Degree SecurityStudent::getDegreeProgram() {
	return DEGREE_TYPE;
}

void SecurityStudent::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = DEGREE_TYPE;
}

void SecurityStudent::print() {
	this->Student::print();
	cout << left << setw(8) << "Degree Program: " << degreeStrings[DEGREE_TYPE] << endl;
}

// deconstructor
SecurityStudent::~SecurityStudent() {
	Student::~Student();
	delete this;
}