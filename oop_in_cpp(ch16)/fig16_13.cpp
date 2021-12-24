#include <iostream>
#include "GradeBook.h"
using namespace std;

int main()
{
    GradeBook gb1( "CS101 Introduction to C++ Programming" );
    GradeBook gb2( "CS102 Data Structures in C++" );

    /* cout << "gb1 created for course: " << gb1.getCourseName()
        << "\ngb2 created for course: " << gb2.getCourseName() << endl; */
    
    cout << "gradeBook1's initial course name is: "
        << gb1.getCourseName()
        << "\ngradeBook1's initial course name is: "
        << gb2.getCourseName() << endl;
    
    // modify gradeBook1's courseName ( with a valid-length string)
    gb1.setCourseName( "CS101 C++ Programming" );

    cout << "\ngradeBook1's course name is: "
        << gb1.getCourseName()
        << "\ngradeBook1's course name is: "
        << gb2.getCourseName() << endl;
}