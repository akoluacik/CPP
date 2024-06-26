// GradeBook class definition. This file presents GradeBook's public
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp

#include <string> // class GradeBook uses C++ standart string class

// GradeBook class definition
class GradeBook
{
public:
    explicit GradeBook( std::string ); // one parameter constructor (explicit)
    void setCourseName( std::string ); // sets the course name
    std::string getCourseName() const; // gets the course name
    void displayMessage() const; // diplays welcome message
private:
    std::string courseName;
};
