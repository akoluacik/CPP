// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h

#include <iostream>
#include "GradeBook.h" // include definition of GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name )
{
    // courseName(name); // member initializer to initialize courseName
    setCourseName( name ); // validate and store courseName
}

// function to set courseName
// ensures the courseName has at most 25 chars.
void GradeBook::setCourseName( string name )
{
    if( name.size() <= 25)
        courseName = name;
    else
    {
        courseName = name.substr(0, 25);
        cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
            << "Limiting courseName to first 25 characters.\n" << endl;
    }
}

/* scope resolution operator ties each member function 
to the class definition */

// function to get courseName
string GradeBook::getCourseName() const
{
    return courseName;
}

// display a welcome message
void GradeBook::displayMessage() const
{
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}
