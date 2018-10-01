#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

const int NUM_STUDENTS = 5;

const string studentData[NUM_STUDENTS] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jacob,Schaible,jschai3@wgu.edu,30,12,15,10,SOFTWARE"
};

class Roster {
public:
	int lastIndex;
	int capacity;
	Student** classRosterArray; // holds data from studentData

	Roster(); // empty constructor
	Roster(int capacity); // sets max size

	void parseNext(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram); // degree program = enum
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID); // should print avg # days in course
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);

	~Roster(); // destructor
};