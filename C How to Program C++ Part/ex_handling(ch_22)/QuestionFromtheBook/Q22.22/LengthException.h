#if !defined(__LENGTH_EXP_H)
#define __LENGTH_EXP_H

#include <stdexcept>

class LengthException : public std::length_error
{
public:
    LengthException(/* args */) : std::length_error("Attempts to exceed length limits!") {}
    ~LengthException() {}
};

#endif // __LENGTH_EXP_H
