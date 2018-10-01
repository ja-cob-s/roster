#include <iostream>
#include <iomanip>
#include "student.h"

using namespace std;

// empty constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourses = new int[DAYS_ARRAY_SIZE];

	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) {
		this->daysInCourses[i] = 0;
	}
}
// full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourses = new int[DAYS_ARRAY_SIZE];

	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) {
		if (i == 0) {
			this->daysInCourses[i] = daysInCourse1;
		}
		else if (i == 1) {
			this->daysInCourses[i] = daysInCourse2;
		}
		else if (i == 2) {
			this->daysInCourses[i] = daysInCourse3;
		}
		else {
			this->daysInCourses[i] = 0;
		}
	}
}

// accessors
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysInCourses() {
	return daysInCourses;
}

// mutators
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourses(int daysInCourses[]) {
	if (this->daysInCourses != nullptr) {
		delete[] this->daysInCourses;
		this->daysInCourses = nullptr;
	}

	this->daysInCourses = new int[DAYS_ARRAY_SIZE];

	for (int i = 0; i < DAYS_ARRAY_SIZE; i++) {
		this->daysInCourses[i] = daysInCourses[i];
	}
}

void Student::print() {
	cout << left                        << setw(5)  << studentID;
	cout << left << "First Name: "      << setw(8)  << firstName;
	cout << left << "Last Name: "       << setw(11) << lastName;
	cout << left << "Age: "             << setw(5)  << age;
	cout << left << "Days In Course: {" << setw(2)  << daysInCourses[0] << ", " << setw(2) << daysInCourses[1] << ", " << setw(2) << daysInCourses[2] << setw(4) << "}";
}

Student::~Student() {
	if (daysInCourses != nullptr) {
		delete[] daysInCourses;
		daysInCourses = nullptr;
	}
}
