#include <stdexcept>

class DivideByZeroException : public std::invalid_argument
{
public:
    DivideByZeroException(/* args */) : std::invalid_argument( "attempted to divide by zero" ) {}
};