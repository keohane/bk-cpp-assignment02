/*****************************************************************************
Filename: Line.cpp
Version: v1.0
Author/Student Name: Brandon Keohane
Student Number: 040719123
Course Name & Number: C++ Programming
Lab Section: 302
Assignment Number: 2
Assignment Name: Vector Graphic With Overloaded Operators
Due Date: 12 November, 2016
Submission Date: 9 November, 2016
Professor Name: A. Tyler
Purpose: Represents a line on a 2d plain
*****************************************************************************/
#include <iostream>
using namespace std;
#include "Point.h"
#include "Line.h"

/*****************************************************************************
Function Name: ostream.operator<<
Purpose: Overloads output for line class
Function In Parameters: os - output stream; p - line to output to output stream
Function Out Parameters: output stream with point output appended
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
ostream& operator<<(ostream& os, Line& l){
	return os << "start Point: " << l.start << endl << "end Point: " << l.end << endl;
}