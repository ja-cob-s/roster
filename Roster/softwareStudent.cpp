#include <iostream>
#include <iomanip>
#include "SoftwareStudent.h"

using namespace std;

//constructors
SoftwareStudent::SoftwareStudent() {
	setDegreeProgram(DEGREE_TYPE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
: Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram) {
	setDegreeProgram(DEGREE_TYPE);
}

// overridden methods
Degree SoftwareStudent::getDegreeProgram() {
	return DEGREE_TYPE;
}

void SoftwareStudent::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = DEGREE_TYPE;
}

void SoftwareStudent::print() {
	this->Student::print();
	cout << left << setw(8) << "Degree Program: " << degreeStrings[DEGREE_TYPE] << endl;
}

// deconstructor
SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
	delete this;
}