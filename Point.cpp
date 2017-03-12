/*****************************************************************************
Filename: Point.cpp
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
Purpose: Object represents a point on a 2d plain
*****************************************************************************/
#include <iostream>
using namespace std;
#include "Point.h"

/*****************************************************************************
Function Name: ostream.operator<<
Purpose: Overloads output for point class
Function In Parameters: os - output stream; p - point to output to output stream
Function Out Parameters: output stream with point output appended
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
ostream& operator<<(ostream& os, Point& p){
	return os << "x = " << p.x << "; y= " << p.y << ".";
}
