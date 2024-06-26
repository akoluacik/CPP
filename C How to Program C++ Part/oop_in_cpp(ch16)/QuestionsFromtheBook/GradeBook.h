#include <string>

class GradeBook
{
public:

    GradeBook( std::string courseName, std::string instructorName );

    void setCourseName( std::string );
    std::string getCourseName() const;

    void setInstructor( std::string ) ;
    std::string getInstructor() const;

    void displayMessage() const;
private:
    std::string courseName;
    std::string instructorName;
};