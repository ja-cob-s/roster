#pragma once
#include <string>
#include "degree.h"

using std::string;

class Student {
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourses;
	Degree degreeProgram;

public:
	const static int DAYS_ARRAY_SIZE = 3;
	
	Student(); // empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram); // full constuctor

	// accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourses();
	virtual Degree getDegreeProgram() = 0;

	// mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourses(int daysInCourses[]);
	virtual void setDegreeProgram(Degree degreeProgram) = 0;
	virtual void print() = 0;

	// deconstructor
	~Student();
};