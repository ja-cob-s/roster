#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

// constructors
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

void Roster::parseNext(string row) {
	string studentID = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int age = 0;
	int daysInCourses[3] = { 0, 0, 0 };
	Degree degreeProgram;
	
	lastIndex++;

	// read student ID
	int rts = studentData[lastIndex].find(",");
	studentID = studentData[lastIndex].substr(0, rts);
	//cout << studentID << endl;

	// read first name
	int lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	firstName = studentData[lastIndex].substr(lts, rts - lts);
	//cout << firstName << endl; 

	// read last name
	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	lastName = studentData[lastIndex].substr(lts, rts - lts);
	//cout << lastName << endl; 

	// read email address
	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	emailAddress = studentData[lastIndex].substr(lts, rts - lts);
	//cout << emailAddress << endl; 

	// read age
	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	age = stoi(studentData[lastIndex].substr(lts, rts - lts));
	//cout << age << endl; 

	// read days in courses
	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	daysInCourses[0] = stoi(studentData[lastIndex].substr(lts, rts - lts));
	//cout << daysInCourses[0] << endl; 

	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	daysInCourses[1] = stoi(studentData[lastIndex].substr(lts, rts - lts));
	//cout << daysInCourses[1] << endl;

	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	daysInCourses[2] = stoi(studentData[lastIndex].substr(lts, rts - lts));
	//cout << daysInCourses[2] << endl; 

	// read degree program
	lts = rts + 1;
	rts = studentData[lastIndex].find(",", lts);
	if (studentData[lastIndex].substr(lts, rts - lts) == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (studentData[lastIndex].substr(lts, rts - lts) == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (studentData[lastIndex].substr(lts, rts - lts) == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}
	else {
		cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
		exit(-1);
	}
	//cout << degreeStrings[degreeProgram] << endl;

	add(studentID, firstName, lastName, emailAddress, age, daysInCourses[0], daysInCourses[1], daysInCourses[2], degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
	
	if (degreeProgram == NETWORK) {
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}
	else if (degreeProgram == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}
	else if (degreeProgram == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}
	else {
		cerr << "INVALID DEGREE PROGRAM! EXITING NOW!" << endl;
		exit(-1);
	}
}

void Roster::remove(string studentID) {
	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			found = true;
		}
	}

	if (found) {
		cout << "Removed student " << studentID << endl;
	}
	else {
		cout << "Student not found!" << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			int* days = classRosterArray[i]->getDaysInCourses();
			cout << "Student ID " << this->classRosterArray[i]->getStudentID() << ": ";
			cout << "Average number of days in course: " << ((days[0] + days[1] + days[2]) / 3) << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Student not found!" << endl;
	}
}

void Roster::printInvalidEmails() {
	cout << "Verifying email addresses:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		cout << "Student ID " << classRosterArray[i]->getStudentID() << ": ";
		bool atSymFound = false;
		bool periodFound = false;
		bool spaceFound = false;

		// check for "@", ".", and " "
		int found = classRosterArray[i]->getEmailAddress().find("@");
		if (found >= 0) {
			atSymFound = true;
		}
		found = classRosterArray[i]->getEmailAddress().find(".");
		if (found >= 0) {
			periodFound = true;
		}
		found = classRosterArray[i]->getEmailAddress().find(" ");
		if (found >= 0) {
			spaceFound = true;
		}

		// print valid or invalid
		if (atSymFound && periodFound && !spaceFound) {
			cout << "Valid email address" << endl;
		}
		else {
			cout << "Invalid email address: " << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	cout << "Printing students in degree program: " << degreeStrings[degreeProgram] << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

// deconstructor
Roster::~Roster() {
	for (int i = 0; i < NUM_STUDENTS; i++) {
		delete this->classRosterArray[i];
	}
	delete this;
}

int main() {
	cout << "Course: Scripting and Programming - Applications - C867\n"
		<< "Programming language: C++\n"
		<< "by Jacob Schaible, Student ID: 000929649\n\n";

	Roster* classRoster = new Roster(NUM_STUDENTS);

	cout << "Parsing data and adding students: ";
	for (int i = 0; i < NUM_STUDENTS; i++) {
		classRoster->parseNext(studentData[i]);
	}
	cout << "DONE." << endl;

	cout << "Displaying all students:" << endl;
	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (int i = 0; i < NUM_STUDENTS; i++) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	
	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->remove("A3");
	
	return 0;
}