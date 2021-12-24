#include <iostream>
#include "GradeBook.h"

GradeBook::GradeBook(std::string courseName, std::string instructorName)

    :courseName(courseName) // member initializer
    ,instructorName(instructorName) // member initializer
{
    // empty constructor body
}

void GradeBook::setCourseName( std::string _courseName )
{
    courseName = _courseName;
}

std::string GradeBook::getCourseName() const
{
    return courseName;
}

void GradeBook::setInstructor(std::string _instructorName )
{
    instructorName = _instructorName;
}

std::string GradeBook::getInstructor() const
{
    return instructorName;
}

void GradeBook::displayMessage() const
{
    std::cout << "Welcome to " << courseName << " course!"
        <<" This course is represented by: " << instructorName << std::endl;
}