/*****************************************************************************
Filename: GraphicElement.cpp
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
Purpose: Represents a graphic element consisting of n number of lines on a 
		 2d plain.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"

/*****************************************************************************
Function Name: GraphicElement Constructor
Purpose: Constructs a graphic element with parameter data
Function In Parameters: pLine - Line pointer; n - name of graphic element
						nLines - number of lines in this graphic element
Function Out Parameters: output stream with point output appended
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
GraphicElement::GraphicElement(Line* pLine, char* n, unsigned int nLines){
	/* If new one has lines */
	if (nLines){
		/* Allocate new lines */
		pLines = new Line[nLines];
		/* Deep copy new lines */
		for (unsigned int i = 0; i < nLines; ++i){
			pLines[i] = pLine[i];
		}
	}
	/* Delete parameter lines */
	delete[]pLine;
	/* Copy name from parameter graphic element */
	strcpy(name, n);
	/* Copy num lines from parameter graphic element */
	numLines = nLines;
}

/*****************************************************************************
Function Name: GraphicElement Constructor
Purpose: Constructs a graphic element with parameter graphic element data
Function In Parameters ge - graphic element to make this graphic element equal
Function Out Parameters: Reference of this modified graphic element
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
GraphicElement::GraphicElement(GraphicElement& ge){
	*this = ge;
}

/*****************************************************************************
Function Name: GraphicElement.operator=
Purpose: Changes this graphic elements data to be the parameters graphic 
		 element data.
Function In Parameters ge - graphic element to make this graphic element equal
Function Out Parameters: Reference of this modified graphic element
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& ge){
	/* Delete pLines */
	delete[]pLines;
	/* If new one has lines */
	if (ge.numLines){
		/* Allocate new lines */
		pLines = new Line[ge.numLines];
		/* Deep copy new lines */
		for (unsigned int i = 0; i < ge.numLines; ++i){
			pLines[i] = ge.pLines[i];
		}
	}
	/* Copy name from parameter graphic element */
	strcpy(name, ge.name);
	/* Copy num lines from parameter graphic element */
	numLines = ge.numLines;
	/* Return a reference to this graphic element */
	return *this;
}

/*****************************************************************************
Function Name: GraphicElement.operator+
Purpose: Appends the two graphic elements
Function In Parameters ge - graphic element to merge with this graphic element
Function Out Parameters: Object of graphic element that is merged together
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
GraphicElement GraphicElement::operator+(GraphicElement& ge){
	/* Used to loop through indexes of array */
	int count = 0;

	/* New number of lines */
	int nLines = numLines + ge.numLines;
	/* New name */
	char n[255];
	/* New lines */
	Line* lines = new Line[nLines];
	/* Concatinate names together */
	strcpy(n,name);
	strcat(n, "_");
	strcat(n, ge.name);
	/* Allocate memory for new lines */
	for (unsigned int i = 0; i < numLines; ++i){
		lines[i] = pLines[i];
	}
	for (int i = numLines; i < nLines; ++i){
		lines[i] = ge.pLines[count++];
	}
	/* Return new graphic element */
	return GraphicElement(lines, n, nLines);
}

/*****************************************************************************
Function Name: ostream.operator<<
Purpose: Overloads output for graphic element class
Function In Parameters: os - output stream; ge - graphic element to print
Function Out Parameters: output stream with graphic element output appended
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
ostream& operator<<(ostream& os, GraphicElement& ge){
	os << "Graphic Element name: " << ge.name << endl;
	for (unsigned int i = 0; i < ge.numLines; ++i){
		os << "Line " << i << ":" << endl;
		os << ge.pLines[i] << endl;
	}
	return os;
}