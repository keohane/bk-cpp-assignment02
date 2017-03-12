/*****************************************************************************
Filename: VectorGraphic.cpp
Version: v1.0
Author/Student Name: Brandon Keohane
Student Number: 040719123
Course Name & Number: C++ Programming
Lab Section: 302
Assignment Number: 2
Assignment Name: Vector Graphic in C++
Due Date: 12 November, 2016
Submission Date: 9 November, 2016
Professor Name: A. Tyler
Purpose: Object represents a vector graphic with graphic elements
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"
#include "Line.h"
#include "GraphicElement.h"
#include "VectorGraphic.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name: GraphicElement operator+
Purpose: Allows user to append a graphic element to the end of the array
Function In Parameters: ge - graphic element reference to append to array
Function Out Parameters: Void
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
void VectorGraphic::operator+=(GraphicElement& ge){
	/* Temp array to get old elements and append new element */
	GraphicElement* pTempElements = new GraphicElement[numGraphicElements + 1];
	/* Deep copy elements */
	for (unsigned int i = 0; i < numGraphicElements; ++i){
		pTempElements[i] = pElements[i];
	}
	/* Copy last element */
	pTempElements[numGraphicElements] = ge;
	/* Delete this pElements */
	delete[]pElements;
	/* Reallocate memory for this pElements */
	pElements = new GraphicElement[numGraphicElements + 1];
	/* Deep copy back into new pElements */
	for (unsigned int i = 0; i < numGraphicElements + 1; ++i){
		pElements[i] = pTempElements[i];
	}
	/* Update size of array */
	++numGraphicElements;
	/* Clean up lines in parameter graphic element */
	delete[] pTempElements;
}

/*****************************************************************************
Function Name: GraphicElement operator[]
Purpose: Allows user to get element in array position specified
Function In Parameters: i - index to get element from
Function Out Parameters: Void
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
GraphicElement& VectorGraphic::operator[](int index){
	return pElements[index];
}

/*****************************************************************************
Function Name: ostream.operator<<
Purpose: Allows user to get element in array position specified
Function In Parameters: os - output stream; vg - vector graphic reference to print 
Function Out Parameters: Void
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
ostream& operator<<(ostream& os, VectorGraphic& vg){
	/* Report this vector graphic */
	os << "VectorGraphic Report" << endl;
	for (unsigned int i = 0; i < vg.numGraphicElements; ++i){
		os << "Reporting Graphic Element " << i << endl;
		os << vg[i];
	}
	return os;
}

/*****************************************************************************
Function Name: AddGraphicElement
Purpose: Adds graphic element to the vector graphic
Function In Parameters: Void
Function Out Parameters: Void
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
void VectorGraphic::AddGraphicElement(){
	char geName[256];
	int nLines, sX, sY, eX, eY;
	Line* lines;

	cout << "ADDING a Graphic Element" << endl;
	cout << "Please enter the name of the new GraphicElement(256 characters): ";
	cin >> geName;

	cout << "How many lines are there in the new GraphicElement? ";
	cin >> nLines;

	lines = new Line[nLines];

	/* Add new Graphic Element */
	for (int index = 0; index < nLines; ++index){
		/* For some reason this was giving warning if they were not initialized, but they are at the beginning... */
		sX = sY = eX = eY = 0;
		/* Get all the coordinates for the line */
		cout << "Please enter the x coord of the start point of line index " << index << ": ";
		cin >> sX;
		cout << "Please enter the y coord of the start point of line index " << index << ": ";
		cin >> sY;
		cout << "Please enter the x coord of the end point of line index " << index << ": ";
		cin >> eX;
		cout << "Please enter the y coord of the end point of line index " << index << ": ";
		cin >> eY;
		/* Add line to line array */
		lines[index] = Line( Point(sX,sY), Point(eX,eY) );
	}
	/* Append this new graphic element */
	*this += GraphicElement(lines, geName, nLines);
}

/*****************************************************************************
Function Name: DeleteGraphicElement
Purpose: Deletes a graphic element specified by user from array
Function In Parameters: Void
Function Out Parameters: Void
Version: v1.0
Author/Student Name: Brandon Keohane
*****************************************************************************/
void VectorGraphic::DeleteGraphicElement(){
	int iCount = 0;
	unsigned short index = 0;
	/* Temp array to get old elements */
	GraphicElement* pTempElements;
	
	/* If there are no graphic elements in vector graphic return */
	if (numGraphicElements == 0) {
		cout << "No Elements to delete." << endl;
		return;
	}

	cout << "Please enter the index of the Graphic Element you wish to delete: ";
	cin >> index;

	/* Must be a valid index */
	if (index > numGraphicElements - 1 || index < 0){
		cout << "Must be an index from 0 to " << numGraphicElements - 1 << ", try again." << endl;
		return;
	}

	/* If when deleted the list will be empty dont allocate memory or copy */
	if (numGraphicElements != 1){
		/* Allocate for new elements array */
		pTempElements = new GraphicElement[numGraphicElements - 1];
		/* Loop and skip index to delete */
		for (unsigned int i = 0; i < numGraphicElements; ++i){
			if (i != index){
				/* Deep copy element */
				pTempElements[iCount] = pElements[i];
				/* Increment index to add to */
				++iCount;
			}
		}
		/* Delete previous elements */
		delete[] pElements;
		/* Allocate for new space */
		pElements = new GraphicElement[numGraphicElements - 1];
		/* Deep copy back to new space */
		for (unsigned int i = 0; i < numGraphicElements - 1; ++i){
			pElements[i] = pTempElements[i];
		}
		/* Update size */
		numGraphicElements = numGraphicElements - 1;
		/* Delete temp array */
		delete[] pTempElements;
	}
	/* Should not allocate memory just delete old */
	else {
		/* Delete array */
		delete[] pElements;
		/* Make it so there are no dangling pointers */
		pElements = nullptr;
		/* Update size */
		numGraphicElements = 0;
	}
}


