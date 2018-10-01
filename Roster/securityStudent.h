#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student {

	const Degree DEGREE_TYPE = SECURITY;

public:
	// constructors
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);

	// overriding virtual methods
	Degree getDegreeProgram();
	void setDegreeProgram(Degree degreeProgram);
	void print();

	// deconstructor
	~SecurityStudent();
};