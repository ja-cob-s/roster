#include <iostream>
#include <iomanip>
#include "networkStudent.h"

using namespace std;

//constructors
NetworkStudent::NetworkStudent() {
	setDegreeProgram(DEGREE_TYPE);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) 
: Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram) {
	setDegreeProgram(DEGREE_TYPE);
}

// overridden methods
Degree NetworkStudent::getDegreeProgram() {
	return DEGREE_TYPE;
}

void NetworkStudent::setDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = DEGREE_TYPE;
}

void NetworkStudent::print() {
	this->Student::print();
	cout << left << setw(8) << "Degree Program: " << degreeStrings[DEGREE_TYPE] << endl;
}

// deconstructor
NetworkStudent::~NetworkStudent() {
	Student::~Student();
	delete this;
}